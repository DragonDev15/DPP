#pragma once

#include <string>
#include <map>
#include <dpp/discord.h>
#include <dpp/dispatcher.h>
#include <spdlog/fwd.h>
#include <dpp/discordclient.h>

namespace dpp {

class cluster {
public:
	dpp::dispatcher dispatch;
	std::map<uint32_t, class DiscordClient*> shards;

	void start(const std::string &token, uint32_t intents = 0, uint32_t shards = 1, uint32_t cluster_id = 0, uint32_t maxclusters = 1, spdlog::logger* log = nullptr);

	void on_voice_state_update (std::function<void(const voice_state_update_t& _event)> _voice_state_update);
	void on_interaction_create (std::function<void(const interaction_create_t& _event)> _interaction_create);
	void on_guild_delete (std::function<void(const guild_delete_t& _event)> _guild_delete);
	void on_channel_delete (std::function<void(const channel_delete_t& _event)> _channel_delete);
	void on_channel_update (std::function<void(const channel_update_t& _event)> _channel_update);
	void on_ready (std::function<void(const ready_t& _event)> _ready);
	void on_message_delete (std::function<void(const message_delete_t& _event)> _message_delete);
	void on_application_command_delete (std::function<void(const application_command_delete_t& _event)> _application_command_delete);
	void on_guild_member_remove (std::function<void(const guild_member_remove_t& _event)> _guild_member_remove);
	void on_application_command_create (std::function<void(const application_command_create_t& _event)> _application_command_create);
	void on_resumed (std::function<void(const resumed_t& _event)> _resumed);
	void on_guild_role_create (std::function<void(const guild_role_create_t& _event)> _guild_role_create);
	void on_typing_start (std::function<void(const typing_start_t& _event)> _typing_start);
	void on_message_reaction_add (std::function<void(const message_reaction_add_t& _event)> _message_reaction_add);
	void on_guild_members_chunk (std::function<void(const guild_members_chunk_t& _event)> _guild_members_chunk);
	void on_message_reaction_remove (std::function<void(const message_reaction_remove_t& _event)> _message_reaction_remove);
	void on_guild_create (std::function<void(const guild_create_t& _event)> _guild_create);
	void on_channel_create (std::function<void(const channel_create_t& _event)> _channel_create);
	void on_message_reaction_remove_emoji (std::function<void(const message_reaction_remove_emoji_t& _event)> _message_reaction_remove_emoji);
	void on_message_delete_bulk (std::function<void(const message_delete_bulk_t& _event)> _message_delete_bulk);
	void on_guild_role_update (std::function<void(const guild_role_update_t& _event)> _guild_role_update);
	void on_guild_role_delete (std::function<void(const guild_role_delete_t& _event)> _guild_role_delete);
	void on_channel_pins_update (std::function<void(const channel_pins_update_t& _event)> _channel_pins_update);
	void on_message_reaction_remove_all (std::function<void(const message_reaction_remove_all_t& _event)> _message_reaction_remove_all);
	void on_voice_server_update (std::function<void(const voice_server_update_t& _event)> _voice_server_update);
	void on_guild_emojis_update (std::function<void(const guild_emojis_update_t& _event)> _guild_emojis_update);
	void on_presence_update (std::function<void(const presence_update_t& _event)> _presence_update);
	void on_webhooks_update (std::function<void(const webhooks_update_t& _event)> _webhooks_update);
	void on_guild_member_add (std::function<void(const guild_member_add_t& _event)> _guild_member_add);
	void on_invite_delete (std::function<void(const invite_delete_t& _event)> _invite_delete);
	void on_guild_update (std::function<void(const guild_update_t& _event)> _guild_update);
	void on_guild_integrations_update (std::function<void(const guild_integrations_update_t& _event)> _guild_integrations_update);
	void on_guild_member_update (std::function<void(const guild_member_update_t& _event)> _guild_member_update);
	void on_application_command_update (std::function<void(const application_command_update_t& _event)> _application_command_update);
	void on_invite_create (std::function<void(const invite_create_t& _event)> _invite_create);
	void on_message_update (std::function<void(const message_update_t& _event)> _message_update);
	void on_user_update (std::function<void(const user_update_t& _event)> _user_update);
	void on_message_create (std::function<void(const message_create_t& _event)> _message_create);
	void on_guild_ban_add (std::function<void(const guild_ban_add_t& _event)> _guild_ban_add);
};

};
