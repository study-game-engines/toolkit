<shader>
	<type name = "fragmentShader" />
	<uniform name = "LightData" />
	<uniform name = "CamData" />
	<uniform name = "Color" />
	<uniform name = "UseIbl" />
	<uniform name = "IblIntensity" />
	<uniform name = "IBLIrradianceMap" />
	<source>
	<!--
		#version 300 es
		precision mediump float;

		// Fixed Declaretions
		struct _LightData
		{
			/*
			Type
				1 : Directional light
				2 : Point light
				3 : Spot light
			*/
			int type[12];
			vec3 pos[12];
			vec3 dir[12];
			vec3 color[12];
			float intensity[12];
			float radius[12];
			float outAngle[12];
			float innAngle[12];
			int activeCount;

			mat4 spaceMatrix[12];
			sampler2D dirAndSpotLightShadowMap[8];
			samplerCube pointLightShadowMap[8];
			int castShadow[12];
			float shadowMinBias[12];
			float shadowMaxBias[12];
		};

		struct _CamData
		{
			vec3 pos;
			vec3 dir;
		};

		uniform _LightData LightData;
		uniform _CamData CamData;
		uniform vec4 Color;

		uniform samplerCube s_texture1;
		uniform float UseIbl;
		uniform float IblIntensity;

		in vec3 v_pos;
		in vec3 v_normal;
		in vec2 v_texture;

		out vec4 fragColor;

		// https://learnopengl.com/Advanced-Lighting/Shadows/Shadow-Mapping
		int CalculateDirectionalShadow(vec3 pos, int index, int dirIndex, vec3 normal)
		{
			vec4 fragPosForLight = LightData.spaceMatrix[index] * vec4(pos, 1.0);

			// Projection divide
			vec3 projCoord = fragPosForLight.xyz / fragPosForLight.w;

			// Transform to [0, 1] range
			projCoord = projCoord * 0.5 + 0.5;

			// Get depth of the current fragment according to lights view
			float currentDepth = projCoord.z;

			// Get closest depth value according to lights view
			float closestDepth = texture(LightData.dirAndSpotLightShadowMap[dirIndex], projCoord.xy).r;

			float bias = max(LightData.shadowMaxBias[index] * (1.0 - dot(normal, -LightData.dir[index])), LightData.shadowMinBias[index]);
			int shadow = currentDepth - bias > closestDepth ? 0 : 1;

			return shadow;
		}

		void main()
		{
			int dirAndSpotLightCount = 0;
			int pointLightCount = 0;

			vec3 n = normalize(v_normal);
			vec3 e = normalize(CamData.pos - v_pos);

			int shadow = 1;
			vec3 irradiance = vec3(0.0);
			for (int i = 0; i < LightData.activeCount; i++)
			{
				vec3 ambient = vec3(0.0);
				vec3 diffuse = vec3(0.0);
				vec3 specular = vec3(0.0);
				if (LightData.type[i] == 2) // Point light
				{
					vec3 fragToLight = LightData.pos[i] - v_pos;

					// No need calculation for the fragments outside of the light radius
					float radiusCheck = clamp(LightData.radius[i] - length(fragToLight), 0.0, 1.0);
					radiusCheck = ceil(radiusCheck);

					vec3 l = normalize(fragToLight);

					// Attenuation
					float constant = 1.0;
					float linear = 0.09;
					float quadratic = 0.032;
					float distance = length(fragToLight);
					float attenuation = 1.0 / (constant + linear * distance + quadratic * (distance * distance));

					// Decrase attenuation heavily near radius
					float cutOff = 0.5;
					attenuation *= clamp
					(
						cutOff * distance + LightData.radius[i] * 0.5 - distance,
						0.0,
						1.0
					);

					// Diffuse
					float diff = max(dot(n, l), 0.0);
					diffuse = diff * LightData.color[i];

					// Specular
					float specularStrength = 0.4;
					vec3 halfwayDir = normalize(l + e);  
					float spec = pow(max(dot(n, halfwayDir), 0.0), 32.0);
					specular = specularStrength * spec * LightData.color[i];

					// Ambient
					float ambientStrength = 0.01;
					ambient = ambientStrength * LightData.color[i];

					diffuse  *= attenuation * radiusCheck;
					specular *= attenuation * radiusCheck;

					pointLightCount += 1;
				}
				else if (LightData.type[i] == 1) // Directional light
				{
					vec3 l = -LightData.dir[i];

					// Diffuse 
					float diff = max(dot(n, l), 0.0);
					diffuse = diff * LightData.color[i];

					// Specular
					float specularStrength = 0.4;
					vec3 halfwayDir = normalize(l + e);  
					float spec = pow(max(dot(n, halfwayDir), 0.0), 32.0);
					specular = specularStrength * spec * LightData.color[i];

					// Ambient
					float ambientStrength = 0.01;
					ambient = ambientStrength * LightData.color[i];

					shadow = (1 - LightData.castShadow[i]) |
						(CalculateDirectionalShadow(v_pos, i, dirAndSpotLightCount, n) & LightData.castShadow[i]);
					dirAndSpotLightCount += 1;
				}
				else if (LightData.type[i] == 3) // Spot light
				{
					vec3 fragToLight = LightData.pos[i] - v_pos;

					// No need calculation for the fragments outside of the light radius
					float radiusCheck = clamp(LightData.radius[i] - length(fragToLight), 0.0, 1.0);
					radiusCheck = ceil(radiusCheck);

					vec3 l = -LightData.dir[i];

					// Attenuation
					float constant = 1.0;
					float linear = 0.09;
					float quadratic = 0.032;
					float distance = length(fragToLight);
					float attenuation = 1.0 /
					(constant + linear * distance + quadratic * (distance * distance));

					// Decrase attenuation heavily near radius
					float cutOff = 0.5;
					attenuation *= clamp
					(
						cutOff * distance + LightData.radius[i] * 0.5 - distance,
						0.0,
						1.0
					);

					// Diffuse
					float diff = max(dot(n, l), 0.0);
					diffuse = diff * LightData.color[i];

					// Specular
					float specularStrength = 0.4;
					vec3 halfwayDir = normalize(l + e);  
					float spec = pow(max(dot(n, halfwayDir), 0.0), 32.0);
					specular = specularStrength * spec * LightData.color[i];

					vec3 lightToFrag = normalize(v_pos -  LightData.pos[i]);
					float theta = dot(lightToFrag, -l);
					float epsilon =  LightData.innAngle[i] - LightData.outAngle[i];
					float intensity = clamp((theta - LightData.outAngle[i]) / epsilon, 0.0, 1.0);

					diffuse *= intensity * radiusCheck * attenuation;
					specular *= intensity * radiusCheck * attenuation;

					dirAndSpotLightCount += 1;
				}

				irradiance += (ambient + diffuse + specular) * LightData.intensity[i] * float(shadow);
			}

			vec3 iblIrradiance = UseIbl * texture(s_texture1, n).rgb;
			irradiance += iblIrradiance * IblIntensity;

			fragColor = vec4(irradiance * Color.xyz, Color.a);
		}
	-->
	</source>
</shader>