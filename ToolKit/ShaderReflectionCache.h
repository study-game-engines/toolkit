#pragma once

#include "Types.h"

namespace ToolKit
{

  // LightData String cache.
  static const StringArray g_lightPosStrCache = {"LightData.pos[0]",
                                                 "LightData.pos[1]",
                                                 "LightData.pos[2]",
                                                 "LightData.pos[3]",
                                                 "LightData.pos[4]",
                                                 "LightData.pos[5]",
                                                 "LightData.pos[6]",
                                                 "LightData.pos[7]",
                                                 "LightData.pos[8]",
                                                 "LightData.pos[9]",
                                                 "LightData.pos[10]",
                                                 "LightData.pos[11]"};

  static const StringArray g_lightDirStrCache = {"LightData.dir[0]",
                                                 "LightData.dir[1]",
                                                 "LightData.dir[2]",
                                                 "LightData.dir[3]",
                                                 "LightData.dir[4]",
                                                 "LightData.dir[5]",
                                                 "LightData.dir[6]",
                                                 "LightData.dir[7]",
                                                 "LightData.dir[8]",
                                                 "LightData.dir[9]",
                                                 "LightData.dir[10]",
                                                 "LightData.dir[11]"};

  static const StringArray g_lightColorStrCache = {"LightData.color[0]",
                                                   "LightData.color[1]",
                                                   "LightData.color[2]",
                                                   "LightData.color[3]",
                                                   "LightData.color[4]",
                                                   "LightData.color[5]",
                                                   "LightData.color[6]",
                                                   "LightData.color[7]",
                                                   "LightData.color[8]",
                                                   "LightData.color[9]",
                                                   "LightData.color[10]",
                                                   "LightData.color[11]"};

  static const StringArray g_lightIntensityStrCache = {
      "LightData.intensity[0]",
      "LightData.intensity[1]",
      "LightData.intensity[2]",
      "LightData.intensity[3]",
      "LightData.intensity[4]",
      "LightData.intensity[5]",
      "LightData.intensity[6]",
      "LightData.intensity[7]",
      "LightData.intensity[8]",
      "LightData.intensity[9]",
      "LightData.intensity[10]",
      "LightData.intensity[11]"};

  static const StringArray g_lightTypeStrCache = {"LightData.type[0]",
                                                  "LightData.type[1]",
                                                  "LightData.type[2]",
                                                  "LightData.type[3]",
                                                  "LightData.type[4]",
                                                  "LightData.type[5]",
                                                  "LightData.type[6]",
                                                  "LightData.type[7]",
                                                  "LightData.type[8]",
                                                  "LightData.type[9]",
                                                  "LightData.type[10]",
                                                  "LightData.type[11]"};

  static const StringArray g_lightRadiusStrCache = {"LightData.radius[0]",
                                                    "LightData.radius[1]",
                                                    "LightData.radius[2]",
                                                    "LightData.radius[3]",
                                                    "LightData.radius[4]",
                                                    "LightData.radius[5]",
                                                    "LightData.radius[6]",
                                                    "LightData.radius[7]",
                                                    "LightData.radius[8]",
                                                    "LightData.radius[9]",
                                                    "LightData.radius[10]",
                                                    "LightData.radius[11]"};

  static const StringArray g_lightOuterAngleStrCache = {
      "LightData.outAngle[0]",
      "LightData.outAngle[1]",
      "LightData.outAngle[2]",
      "LightData.outAngle[3]",
      "LightData.outAngle[4]",
      "LightData.outAngle[5]",
      "LightData.outAngle[6]",
      "LightData.outAngle[7]",
      "LightData.outAngle[8]",
      "LightData.outAngle[9]",
      "LightData.outAngle[10]",
      "LightData.outAngle[11]"};

  static const StringArray g_lightInnerAngleStrCache = {
      "LightData.innAngle[0]",
      "LightData.innAngle[1]",
      "LightData.innAngle[2]",
      "LightData.innAngle[3]",
      "LightData.innAngle[4]",
      "LightData.innAngle[5]",
      "LightData.innAngle[6]",
      "LightData.innAngle[7]",
      "LightData.innAngle[8]",
      "LightData.innAngle[9]",
      "LightData.innAngle[10]",
      "LightData.innAngle[11]"};

  static const StringArray g_lightprojectionViewMatrixStrCache = {
      "LightData.projectionViewMatrix[0]",
      "LightData.projectionViewMatrix[1]",
      "LightData.projectionViewMatrix[2]",
      "LightData.projectionViewMatrix[3]",
      "LightData.projectionViewMatrix[4]",
      "LightData.projectionViewMatrix[5]",
      "LightData.projectionViewMatrix[6]",
      "LightData.projectionViewMatrix[7]",
      "LightData.projectionViewMatrix[8]",
      "LightData.projectionViewMatrix[9]",
      "LightData.projectionViewMatrix[10]",
      "LightData.projectionViewMatrix[11]"};

  static const StringArray g_lightCastShadowStrCache = {
      "LightData.castShadow[0]",
      "LightData.castShadow[1]",
      "LightData.castShadow[2]",
      "LightData.castShadow[3]",
      "LightData.castShadow[4]",
      "LightData.castShadow[5]",
      "LightData.castShadow[6]",
      "LightData.castShadow[7]",
      "LightData.castShadow[8]",
      "LightData.castShadow[9]",
      "LightData.castShadow[10]",
      "LightData.castShadow[11]"};

  static const StringArray g_lightShadowMapCameraFarStrCache = {
      "LightData.shadowMapCameraFar[0]",
      "LightData.shadowMapCameraFar[1]",
      "LightData.shadowMapCameraFar[2]",
      "LightData.shadowMapCameraFar[3]",
      "LightData.shadowMapCameraFar[4]",
      "LightData.shadowMapCameraFar[5]",
      "LightData.shadowMapCameraFar[6]",
      "LightData.shadowMapCameraFar[7]",
      "LightData.shadowMapCameraFar[8]",
      "LightData.shadowMapCameraFar[9]",
      "LightData.shadowMapCameraFar[10]",
      "LightData.shadowMapCameraFar[11]"};

  static const StringArray g_lightPCFSamplesStrCache = {
      "LightData.PCFSamples[0]",
      "LightData.PCFSamples[1]",
      "LightData.PCFSamples[2]",
      "LightData.PCFSamples[3]",
      "LightData.PCFSamples[4]",
      "LightData.PCFSamples[5]",
      "LightData.PCFSamples[6]",
      "LightData.PCFSamples[7]",
      "LightData.PCFSamples[8]",
      "LightData.PCFSamples[9]",
      "LightData.PCFSamples[10]",
      "LightData.PCFSamples[11]"};

  static const StringArray g_lightPCFRadiusStrCache = {
      "LightData.PCFRadius[0]",
      "LightData.PCFRadius[1]",
      "LightData.PCFRadius[2]",
      "LightData.PCFRadius[3]",
      "LightData.PCFRadius[4]",
      "LightData.PCFRadius[5]",
      "LightData.PCFRadius[6]",
      "LightData.PCFRadius[7]",
      "LightData.PCFRadius[8]",
      "LightData.PCFRadius[9]",
      "LightData.PCFRadius[10]",
      "LightData.PCFRadius[11]"};

  static const StringArray g_lightsoftShadowsStrCache = {
      "LightData.softShadows[0]",
      "LightData.softShadows[1]",
      "LightData.softShadows[2]",
      "LightData.softShadows[3]",
      "LightData.softShadows[4]",
      "LightData.softShadows[5]",
      "LightData.softShadows[6]",
      "LightData.softShadows[7]",
      "LightData.softShadows[8]",
      "LightData.softShadows[9]",
      "LightData.softShadows[10]",
      "LightData.softShadows[11]"};

  static const StringArray g_lightBleedingReductionStrCache = {
      "LightData.lightBleedingReduction[0]",
      "LightData.lightBleedingReduction[1]",
      "LightData.lightBleedingReduction[2]",
      "LightData.lightBleedingReduction[3]",
      "LightData.lightBleedingReduction[4]",
      "LightData.lightBleedingReduction[5]",
      "LightData.lightBleedingReduction[6]",
      "LightData.lightBleedingReduction[7]",
      "LightData.lightBleedingReduction[8]",
      "LightData.lightBleedingReduction[9]",
      "LightData.lightBleedingReduction[10]",
      "LightData.lightBleedingReduction[11]"};

  static const StringArray g_lightShadowAtlasLayerStrCache = {
      "LightData.shadowAtlasLayer[0]",
      "LightData.shadowAtlasLayer[1]",
      "LightData.shadowAtlasLayer[2]",
      "LightData.shadowAtlasLayer[3]",
      "LightData.shadowAtlasLayer[4]",
      "LightData.shadowAtlasLayer[5]",
      "LightData.shadowAtlasLayer[6]",
      "LightData.shadowAtlasLayer[7]",
      "LightData.shadowAtlasLayer[8]",
      "LightData.shadowAtlasLayer[9]",
      "LightData.shadowAtlasLayer[10]",
      "LightData.shadowAtlasLayer[11]"};

  static const StringArray g_lightShadowAtlasEdgeRatioStrCache = {
      "LightData.shadowAtlasEdgeRatio[0]",
      "LightData.shadowAtlasEdgeRatio[1]",
      "LightData.shadowAtlasEdgeRatio[2]",
      "LightData.shadowAtlasEdgeRatio[3]",
      "LightData.shadowAtlasEdgeRatio[4]",
      "LightData.shadowAtlasEdgeRatio[5]",
      "LightData.shadowAtlasEdgeRatio[6]",
      "LightData.shadowAtlasEdgeRatio[7]",
      "LightData.shadowAtlasEdgeRatio[8]",
      "LightData.shadowAtlasEdgeRatio[9]",
      "LightData.shadowAtlasEdgeRatio[10]",
      "LightData.shadowAtlasEdgeRatio[11]"};

    static const StringArray g_lightShadowResolutionStrCache = {
      "LightData.shadowResolution[0]",
      "LightData.shadowResolution[1]",
      "LightData.shadowResolution[2]",
      "LightData.shadowResolution[3]",
      "LightData.shadowResolution[4]",
      "LightData.shadowResolution[5]",
      "LightData.shadowResolution[6]",
      "LightData.shadowResolution[7]",
      "LightData.shadowResolution[8]",
      "LightData.shadowResolution[9]",
      "LightData.shadowResolution[10]",
      "LightData.shadowResolution[11]"};

  static const StringArray g_lightShadowAtlasCoordStrCache = {
      "LightData.shadowAtlasCoord[0]",
      "LightData.shadowAtlasCoord[1]",
      "LightData.shadowAtlasCoord[2]",
      "LightData.shadowAtlasCoord[3]",
      "LightData.shadowAtlasCoord[4]",
      "LightData.shadowAtlasCoord[5]",
      "LightData.shadowAtlasCoord[6]",
      "LightData.shadowAtlasCoord[7]",
      "LightData.shadowAtlasCoord[8]",
      "LightData.shadowAtlasCoord[9]",
      "LightData.shadowAtlasCoord[10]",
      "LightData.shadowAtlasCoord[11]"};

  static const StringArray g_ssaoSamplesStrCache = {
      "samples[0]",  "samples[1]",  "samples[2]",  "samples[3]",  "samples[4]",
      "samples[5]",  "samples[6]",  "samples[7]",  "samples[8]",  "samples[9]",
      "samples[10]", "samples[11]", "samples[12]", "samples[13]", "samples[14]",
      "samples[15]", "samples[16]", "samples[17]", "samples[18]", "samples[19]",
      "samples[20]", "samples[21]", "samples[22]", "samples[23]", "samples[24]",
      "samples[25]", "samples[26]", "samples[27]", "samples[28]", "samples[29]",
      "samples[30]", "samples[31]", "samples[32]", "samples[33]", "samples[34]",
      "samples[35]", "samples[36]", "samples[37]", "samples[38]", "samples[39]",
      "samples[40]", "samples[41]", "samples[42]", "samples[43]", "samples[44]",
      "samples[45]", "samples[46]", "samples[47]", "samples[48]", "samples[49]",
      "samples[50]", "samples[51]", "samples[52]", "samples[53]", "samples[54]",
      "samples[55]", "samples[56]", "samples[57]", "samples[58]", "samples[59]",
      "samples[60]", "samples[61]", "samples[62]", "samples[63]"};

} // namespace ToolKit
