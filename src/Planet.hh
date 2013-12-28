/*
  Planet.hh

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

#pragma once

#include <string>

#include "Vector.hh"

#define PLANET_KERBIN 0

// Conversion factor for pressure and density in kg/(atm*m^3)
#define CONVERSION_FACTOR 1.2230948554874

class Planet {

private:
  std::string name;

  double mass;                     // in kg
  double radius;                   // in m
  double scale_height;             // in m
  double p_0;                      // in atm
  double sidereal_rotation_period; // in s
  double soi;                      // in m

  double atmospheric_height;       // in m

  void init_atmospheric_height();
public:
  Planet(std::string p_name, double p_mass, double p_radius,
	 double p_scale_height, double p_p_0,
	 double p_sidereal_rotation_period, double p_soi);
  Planet(std::string planet_name);
  Planet(int planet_id);
  void init_kerbin();
  double get_atmospheric_height();
  std::string get_name();
  double pressure (double altitude);
  double density (double altitude);
  Vector ground_velocity (Vector pos, Vector vel);
};
