/*
  Engine.hh

  Copyright 2013 Mhoram Kerbin

  This file is part of KaPRI.

  KaPRI is free software: you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  KaPRI is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Foobar.  If not, see <http://www.gnu.org/licenses/>.

 */

#pragma once

#include <string>


#define ENG_LV_T30   0
#define ENG_LV_T45   1
#define ENG_LV_909   2
#define ENG_MAINSAIL 3
#define ENG_LV_N     4

class Engine {
private:
  std::string name;

  double mass;     // in kg
  double thrust;   // in kN
  double drag;     // dimensionless
  double isp_1atm; // in m/s
  double isp_vac;  // in m/s

public:
  Engine(std::string name, double mass, double thrust, double drag,
		 double isp_1atm, double isp_vac);
  double get_mass();
  double get_thrust();
  double get_isp(double pressure);
};
