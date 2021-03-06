/* xoreos - A reimplementation of BioWare's Aurora engine
 *
 * xoreos is the legal property of its developers, whose names
 * can be found in the AUTHORS file distributed with this source
 * distribution.
 *
 * xoreos is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * xoreos is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with xoreos. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file
 *  Trigger in a Star Wars: Knights of the Old Republic area.
 */

#ifndef ENGINES_KOTOR_TRIGGER_H
#define ENGINES_KOTOR_TRIGGER_H

#include "src/engines/aurora/trigger.h"

#include "src/engines/kotor/object.h"

namespace Engines {

namespace KotOR {

class Trigger : public ::Engines::Trigger, public Object {
public:
	Trigger(const Aurora::GFF3Struct &gff);

	// .--- Object
	void show();
	void hide();
	void hideSoft();
	bool isVisible() const;
	// '---
protected:
	void load(const Aurora::GFF3Struct &gff);
	void loadBlueprint(const Common::UString &resRef);
};

} // End of namespace KotOR

} // End of namespace Engines

#endif // ENGINES_KOTOR_TRIGGER_H
