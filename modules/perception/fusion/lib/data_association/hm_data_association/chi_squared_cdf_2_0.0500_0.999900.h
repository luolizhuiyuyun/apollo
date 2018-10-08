/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#pragma once


#include <cstdlib>

namespace apollo {
namespace perception {
namespace fusion {

static double ChiSquaredCdf2TableTable[] = {
    0.000000, 0.024690, 0.048771, 0.072257, 0.095163, 0.117503, 0.139292,
    0.160543, 0.181269, 0.201484, 0.221199, 0.240428, 0.259182, 0.277473,
    0.295312, 0.312711, 0.329680, 0.346230, 0.362372, 0.378115, 0.393469,
    0.408445, 0.423050, 0.437295, 0.451188, 0.464739, 0.477954, 0.490844,
    0.503415, 0.515675, 0.527633, 0.539296, 0.550671, 0.561765, 0.572585,
    0.583138, 0.593430, 0.603469, 0.613259, 0.622808, 0.632121, 0.641204,
    0.650062, 0.658702, 0.667129, 0.675348, 0.683363, 0.691181, 0.698806,
    0.706242, 0.713495, 0.720569, 0.727468, 0.734197, 0.740760, 0.747160,
    0.753403, 0.759492, 0.765430, 0.771221, 0.776870, 0.782379, 0.787752,
    0.792992, 0.798103, 0.803088, 0.807950, 0.812692, 0.817316, 0.821827,
    0.826226, 0.830517, 0.834701, 0.838782, 0.842763, 0.846645, 0.850431,
    0.854124, 0.857726, 0.861239, 0.864665, 0.868006, 0.871265, 0.874444,
    0.877544, 0.880567, 0.883516, 0.886392, 0.889197, 0.891933, 0.894601,
    0.897203, 0.899741, 0.902217, 0.904631, 0.906986, 0.909282, 0.911522,
    0.913706, 0.915837, 0.917915, 0.919942, 0.921918, 0.923846, 0.925726,
    0.927560, 0.929349, 0.931093, 0.932794, 0.934454, 0.936072, 0.937651,
    0.939190, 0.940691, 0.942156, 0.943584, 0.944977, 0.946335, 0.947660,
    0.948953, 0.950213, 0.951442, 0.952641, 0.953810, 0.954951, 0.956063,
    0.957148, 0.958206, 0.959238, 0.960244, 0.961226, 0.962183, 0.963117,
    0.964027, 0.964916, 0.965782, 0.966627, 0.967451, 0.968254, 0.969038,
    0.969803, 0.970548, 0.971275, 0.971985, 0.972676, 0.973351, 0.974009,
    0.974651, 0.975276, 0.975887, 0.976482, 0.977063, 0.977629, 0.978182,
    0.978720, 0.979246, 0.979758, 0.980258, 0.980745, 0.981221, 0.981684,
    0.982137, 0.982578, 0.983008, 0.983427, 0.983837, 0.984236, 0.984625,
    0.985004, 0.985375, 0.985736, 0.986088, 0.986431, 0.986766, 0.987093,
    0.987412, 0.987723, 0.988026, 0.988321, 0.988610, 0.988891, 0.989165,
    0.989433, 0.989694, 0.989948, 0.990196, 0.990438, 0.990674, 0.990905,
    0.991129, 0.991348, 0.991562, 0.991770, 0.991973, 0.992172, 0.992365,
    0.992553, 0.992737, 0.992917, 0.993091, 0.993262, 0.993428, 0.993591,
    0.993749, 0.993903, 0.994054, 0.994201, 0.994344, 0.994483, 0.994620,
    0.994752, 0.994882, 0.995008, 0.995132, 0.995252, 0.995369, 0.995483,
    0.995595, 0.995704, 0.995810, 0.995913, 0.996014, 0.996113, 0.996209,
    0.996302, 0.996393, 0.996482, 0.996569, 0.996654, 0.996737, 0.996817,
    0.996896, 0.996972, 0.997047, 0.997120, 0.997191, 0.997261, 0.997328,
    0.997394, 0.997458, 0.997521, 0.997582, 0.997642, 0.997700, 0.997757,
    0.997813, 0.997867, 0.997919, 0.997971, 0.998021, 0.998070, 0.998117,
    0.998164, 0.998209, 0.998253, 0.998296, 0.998338, 0.998379, 0.998419,
    0.998459, 0.998497, 0.998534, 0.998570, 0.998605, 0.998640, 0.998673,
    0.998706, 0.998738, 0.998769, 0.998799, 0.998829, 0.998858, 0.998886,
    0.998914, 0.998941, 0.998967, 0.998992, 0.999017, 0.999041, 0.999065,
    0.999088, 0.999111, 0.999133, 0.999154, 0.999175, 0.999195, 0.999215,
    0.999235, 0.999253, 0.999272, 0.999290, 0.999307, 0.999324, 0.999341,
    0.999357, 0.999373, 0.999389, 0.999404, 0.999419, 0.999433, 0.999447,
    0.999461, 0.999474, 0.999487, 0.999500, 0.999512, 0.999524, 0.999536,
    0.999547, 0.999558, 0.999569, 0.999580, 0.999590, 0.999600, 0.999610,
    0.999620, 0.999629, 0.999638, 0.999647, 0.999656, 0.999665, 0.999673,
    0.999681, 0.999689, 0.999696, 0.999704, 0.999711, 0.999718, 0.999725,
    0.999732, 0.999739, 0.999745, 0.999751, 0.999758, 0.999764, 0.999769,
    0.999775, 0.999781, 0.999786, 0.999791, 0.999797, 0.999802, 0.999806,
    0.999811, 0.999816, 0.999820, 0.999825, 0.999829, 0.999833, 0.999838,
    0.999842, 0.999845, 0.999849, 0.999853, 0.999857, 0.999860, 0.999864,
    0.999867, 0.999870, 0.999873, 0.999877, 0.999880, 0.999883, 0.999886,
    0.999888, 0.999891, 0.999894, 0.999896, 0.999899,
};

inline double ChiSquaredCdf2TableFun(double dist) {
  static constexpr double step = 0.050000;
  static const size_t table_size =
      sizeof(ChiSquaredCdf2TableTable) / sizeof(double);
  double dist_ind = dist / step;
  int dist_int = dist_ind;
  double w = dist_ind - dist_int;
  if (dist_ind >= table_size - 1) {
    return 1.0;
  }
  return (ChiSquaredCdf2TableTable[dist_int] * (1 - w) +
          ChiSquaredCdf2TableTable[dist_int + 1] * w);
}

}  // namespace fusion
}  // namespace perception
}  // namespace apollo
