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
 *  The ingame GUI.
 */

#ifndef ENGINES_KOTOR_GUI_INGAME_INGAME_H
#define ENGINES_KOTOR_GUI_INGAME_INGAME_H

#include "src/engines/aurora/console.h"

#include "src/engines/kotor/module.h"
#include "src/engines/kotor/inventory.h"

#include "src/engines/kotor/gui/ingame/hud.h"

namespace Engines {

namespace KotOR {

class IngameGUI {
public:
	IngameGUI(Module &module, ::Engines::Console *console = 0);

	void show(); ///< Show the ingame GUI elements.
	void hide(); ///< Hide the ingame GUI elements.

	/** Set the minimap with the specified id and both scaling points. */
	void setMinimap(const Common::UString &map, int northAxis,
	                float worldPt1X, float worldPt1Y, float worldPt2X, float worldPt2Y,
	                float mapPt1X, float mapPt1Y, float mapPt2X, float mapPt2Y);
	/** Set the position for the minimap. */
	void setPosition(float x, float y);

	void setReturnStrref(uint32 id);
	void setReturnQueryStrref(uint32 id);
	void setReturnEnabled(bool enabled);

	// Container inventory handling
	void showContainer(Inventory &inv);

	// Party handling.
	void setPartyLeader(Creature *creature);
	void setPartyMember1(Creature *creature);
	void setPartyMember2(Creature *creature);

	void addEvent(const Events::Event &event);
	void processEventQueue();

private:
	Common::ScopedPtr<HUD> _hud;
};

} // End of namespace KotOR

} // End of namespace Engines

#endif // ENGINES_KOTOR_GUI_INGAME_INGAME_H
