/*
 * Generate C wrapper and Perl 6 bindings for a C++ class
 * Copyright (C) 2015 Rob Hoelz (rob AT hoelz.ro)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <cstring>
#include <string>

#include <xapian.h>

#include "version-check.h"

extern "C" {

typedef Xapian::Stem *xapian_stem;

xapian_stem
xapian_stem_new(void) throw ()
{
    return new Xapian::Stem();
}

xapian_stem
xapian_stem_new2(const char * language) throw ()
{
    return new Xapian::Stem(std::string(language));
}

void
xapian_stem_free(xapian_stem self) throw ()
{
    delete self;
}

const char *
xapian_stem_call(xapian_stem self, const char * word) throw ()
{
    std::string value = (*self)(std::string(word));
    return strdup(value.c_str());
}

const char *
xapian_stem_get_description(xapian_stem self) throw ()
{
    std::string value = self->get_description();
    return strdup(value.c_str());
}

}
