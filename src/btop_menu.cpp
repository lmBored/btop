/* Copyright 2021 Aristocratos (jakob@qvantnet.com)

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

	   http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

indent = tab
tab-size = 4
*/

#include <vector>
#include <deque>
#include <robin_hood.h>
#include <array>

#include <btop_menu.hpp>
#include <btop_tools.hpp>
#include <btop_config.hpp>
#include <btop_theme.hpp>
#include <btop_draw.hpp>

using std::vector, std::deque, robin_hood::unordered_flat_map, std::array;

namespace Menu {

   atomic<bool> active (false);
   string output;

   unordered_flat_map<string, Input::Mouse_loc> mouse_mappings;

   const unordered_flat_map<string, unordered_flat_map<string, vector<string>>> menus = {
		{ "options", {
			{ "normal", {
				"┌─┐┌─┐┌┬┐┬┌─┐┌┐┌┌─┐",
				"│ │├─┘ │ ││ ││││└─┐",
				"└─┘┴   ┴ ┴└─┘┘└┘└─┘"
				} },
			{ "selected", {
				"╔═╗╔═╗╔╦╗╦╔═╗╔╗╔╔═╗",
				"║ ║╠═╝ ║ ║║ ║║║║╚═╗",
				"╚═╝╩   ╩ ╩╚═╝╝╚╝╚═╝"
				} }
		} },
		{ "help", {
			{ "normal", {
				"┬ ┬┌─┐┬  ┌─┐",
				"├─┤├┤ │  ├─┘",
				"┴ ┴└─┘┴─┘┴  "
				} },
			{ "selected", {
				"╦ ╦╔═╗╦  ╔═╗",
				"╠═╣║╣ ║  ╠═╝",
				"╩ ╩╚═╝╩═╝╩  "
				} }
		} },
		{ "quit", {
			{ "normal", {
				"┌─┐ ┬ ┬ ┬┌┬┐",
				"│─┼┐│ │ │ │ ",
				"└─┘└└─┘ ┴ ┴ "
				} },
			{ "selected", {
				"╔═╗ ╦ ╦ ╦╔╦╗ ",
				"║═╬╗║ ║ ║ ║  ",
				"╚═╝╚╚═╝ ╩ ╩  "
				} }
		} }
	};
}