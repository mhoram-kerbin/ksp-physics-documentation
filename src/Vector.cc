/*
  Vector.cc

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

#include <cmath>
#include "Vector.hh"

Vector::Vector (double x, double y, double z) :
  x(x), y(y), z(z)
{ }

double Vector::norm ()
{
  return sqrt(x*x+y*y+z*z);
}

double Vector::operator* (const Vector& b)
{
  return x*b.x + y*b.y + z*b.z;
}

Vector Vector::operator* (const double& f)
{
  return Vector(x*f, y*f, z*f);
}

Vector Vector::operator+ (const Vector& b)
{
  return Vector(x+b.x, y+b.y, z+b.z);
}

Vector Vector::operator- (const Vector& b)
{
  return Vector(x-b.x, y-b.y, z-b.z);
}

Vector Vector::operator/ (const Vector& b)
{
  return Vector(y*b.z - z*b.y,
		z*b.x - x*b.z,
		x*b.y - y*b.x);
}
