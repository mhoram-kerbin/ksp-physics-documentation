/*
  planet.cc

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

#define _USE_MATH_DEFINES
#include <cmath>

#include "planet.hh"

Planet::Planet (std::string name, double mass, double radius,
	double scale_height, double p_0,
	double sidereal_rotation_period, double soi)
  : name(name), mass(mass), radius(radius), scale_height(scale_height),
    p_0(p_0), sidereal_rotation_period(sidereal_rotation_period),
    soi(soi)
{
  init_atmospheric_height();
}

Planet::Planet (std::string planet_name)
{
  if (planet_name == "Kerbin") {
	init_kerbin();
  }
}

Planet::Planet(int planet_id)
{
  if (planet_id == PLANET_KERBIN) {
	init_kerbin();
  }
}

void Planet::init_kerbin()
{
  name = "Kerbin";
  mass = 5.2915793E22;
  radius = 600000;
  scale_height = 5000;
  p_0 = 1;
  sidereal_rotation_period = 21600;
  soi = 84159286;
  init_atmospheric_height();
}

void Planet::init_atmospheric_height()
{
  if (p_0 > 0) {
    atmospheric_height = -log( 1 / (1000000 * p_0)) * scale_height;
  } else {
    atmospheric_height = 0;
  }
}

double Planet::get_atmospheric_height()
{
  return atmospheric_height;
}

std::string Planet::get_name()
{
  return name;
}

/*
  Return the atmospheric pressure at given altitude in atm
*/
double Planet::pressure (double altitude)
{
  if (altitude + radius > atmospheric_height) {
    return 0;
  } else {
    return p_0 * exp(- altitude / scale_height);
  }
}

/*
 Return the density at given altitude in kg m^-3
*/
double Planet::density (double altitude)
{
  return CONVERSION_FACTOR * pressure(altitude);
}

vector Planet::ground_velocity (vector pos, vector vel)
{
  double posN = pos.norm();
  double longitude = atan2(pos.y, pos.x);
  double latitude = atan2(pos.z, sqrt(pos.x*pos.x + pos.y*pos.y));

  vector stv = vector(-sin(longitude), cos(longitude), 0) *
    (posN * 2 * M_PI * cos(latitude) / sidereal_rotation_period);
  return vel - stv;
}
