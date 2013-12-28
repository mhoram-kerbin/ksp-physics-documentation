/*
  engine.cc

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

#include "engine.hh"

engine::engine (std::string name, double mass, double thrust, double drag,
				double isp_1atm, double isp_vac)
  : name(name), mass(mass), thrust(thrust), drag(drag),
	isp_1atm(isp_1atm), isp_vac(isp_vac)
{ }

double engine::get_mass()
{
  return mass;
}

double engine::get_thrust()
{
  return thrust;
}

double engine::get_isp(double pressure)
{
  double real_p;
  if (pressure > 1) {
	real_p = 1;
  } else {
	real_p = pressure;
  }

  return isp_1atm * real_p + isp_vac * (1 - real_p);

}
