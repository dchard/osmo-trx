/*
 * Copyright (C) 2017 Alexander Chemeris <Alexander.Chemeris@fairwaves.co>
 *
 * SPDX-License-Identifier: LGPL-2.1+
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 */

#include "PRBS.h"
#include <iostream>
#include <cstdlib>
#include <assert.h>

void testPrbs(PRBS &prbs, uint64_t expectedPeriod)
{
  uint64_t period = 0;
  do {
    std::cout << prbs.generateBit();
    period++;
  } while (!prbs.isFinished());
  std::cout << std::endl;
  std::cout << "Period: " << period << std::endl;
  assert(period == expectedPeriod);
}

int main(int argc, char *argv[])
{
  PRBS9 prbs9(0x01);
  testPrbs(prbs9, (1<<9)-1);
  PRBS15 prbs15(0x01);
  testPrbs(prbs15, (1<<15)-1);
}
