#include <dpp/discord.h>
#include <dpp/event.h>
#include <string>
#include <iostream>
#include <fstream>
#include <dpp/discordclient.h>
#include <dpp/discordevents.h>
#include <dpp/discord.h>
#include <dpp/cache.h>
#include <dpp/stringops.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void guild_members_chunk::handle(class DiscordClient* client, json &j) {
	json &d = j["d"];
	dpp::guild* g = dpp::find_guild(SnowflakeNotNull(&d, "guild_id"));
	if (g) {
		/* Store guild members */
		for (auto & userrec : d["members"]) {
			json & userspart = userrec["user"];
			dpp::user* u = dpp::find_user(SnowflakeNotNull(&userspart, "id"));
			if (!u) {
				u = new dpp::user();
				u->fill_from_json(&userspart);
				dpp::get_user_cache()->store(u);
			}
			dpp::guild_member* gm = new dpp::guild_member();
			gm->fill_from_json(&userrec, g, u);
			g->members[u->id] = gm;
		}
	}
}

