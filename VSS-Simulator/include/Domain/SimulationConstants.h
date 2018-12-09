/*
   The MIT License (MIT)

   Copyright (c) 2016 Lucas Borsatto Simão

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.
 */
#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

namespace simulator {
  const float PI = 3.141592653589793238462643383279502884;
  const float C_MASSA_ROBO = 0.200;
  const float SCALE_WORLD = 100; //Defines the centimeter as unit of measurement in the world. Used in non-linear equations to convert centimeter in meter (SI)

  const float FIELD_WIDTH = 150;
  const float GOAL_WIDTH = 10;
  const float FIELD_HEIGHT = 130;
}
#endif
