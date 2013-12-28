/*
  Cartesian.hh

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

#include "Orbit.hh"

class Cartesian {

private:
  Vector pos;
  Vector vel;
  double gravitational_parameter;
public:
  Cartesian(Vecor pos, Vector vel, double gravitational_parameter);
  Vector get_pos();
  Vector get_vel();
};
