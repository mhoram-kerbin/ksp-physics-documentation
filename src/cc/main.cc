/*
  main.cc

  Copyright 2013 Mhoram Kerbin

  This file is part of KaPRI.

  KaPRI is free software: you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Foobar is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Foobar.  If not, see <http://www.gnu.org/licenses/>.

 */

#include <iostream>

#include "Planet.hh"

int main ()
{
  Planet kerbin = Planet(PLANET_KERBIN);
  std::string dd = kerbin.get_name();

  std::cout << dd;
  std::cout << kerbin.get_atmospheric_height();
  return 0;
}
