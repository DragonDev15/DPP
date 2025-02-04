#include <map>
#include <dpp/discord.h>
#include <dpp/cluster.h>
#include <dpp/discordclient.h>
#include <spdlog/spdlog.h>

namespace dpp {

void cluster::start(const std::string &token, uint32_t intents, uint32_t shards, uint32_t cluster_id, uint32_t maxclusters, spdlog::logger* log) {
	/* Start up all shards */
	for (uint32_t s = 0; s < shards; ++s) {
		/* Filter out shards that arent part of the current cluster, if the bot is clustered */
		if (s % maxclusters == cluster_id) {
			/* TODO: DiscordClient should spawn a thread in its Run() */
			this->shards[s] = new DiscordClient(this, s, shards, token, intents, log);
			this->shards[s]->Run();
			::sleep(5);
		}
	}
}

void cluster::on_voice_state_update (std::function<void(const voice_state_update_t& _event)> _voice_state_update) {
	this->dispatch.voice_state_update = _voice_state_update; 
}

void cluster::on_interaction_create (std::function<void(const interaction_create_t& _event)> _interaction_create) {
	this->dispatch.interaction_create = _interaction_create; 
}

void cluster::on_guild_delete (std::function<void(const guild_delete_t& _event)> _guild_delete) {
	this->dispatch.guild_delete = _guild_delete; 
}

void cluster::on_channel_delete (std::function<void(const channel_delete_t& _event)> _channel_delete) {
	this->dispatch.channel_delete = _channel_delete; 
}

void cluster::on_channel_update (std::function<void(const channel_update_t& _event)> _channel_update) {
	this->dispatch.channel_update = _channel_update; 
}

void cluster::on_ready (std::function<void(const ready_t& _event)> _ready) {
	this->dispatch.ready = _ready; 
}

void cluster::on_message_delete (std::function<void(const message_delete_t& _event)> _message_delete) {
	this->dispatch.message_delete = _message_delete; 
}

void cluster::on_application_command_delete (std::function<void(const application_command_delete_t& _event)> _application_command_delete) {
	this->dispatch.application_command_delete = _application_command_delete; 
}

void cluster::on_guild_member_remove (std::function<void(const guild_member_remove_t& _event)> _guild_member_remove) {
	this->dispatch.guild_member_remove = _guild_member_remove; 
}

void cluster::on_application_command_create (std::function<void(const application_command_create_t& _event)> _application_command_create) {
	this->dispatch.application_command_create = _application_command_create; 
}

void cluster::on_resumed (std::function<void(const resumed_t& _event)> _resumed) {
	this->dispatch.resumed = _resumed; 
}

void cluster::on_guild_role_create (std::function<void(const guild_role_create_t& _event)> _guild_role_create) {
	this->dispatch.guild_role_create = _guild_role_create; 
}

void cluster::on_typing_start (std::function<void(const typing_start_t& _event)> _typing_start) {
	this->dispatch.typing_start = _typing_start; 
}

void cluster::on_message_reaction_add (std::function<void(const message_reaction_add_t& _event)> _message_reaction_add) {
	this->dispatch.message_reaction_add = _message_reaction_add; 
}

void cluster::on_guild_members_chunk (std::function<void(const guild_members_chunk_t& _event)> _guild_members_chunk) {
	this->dispatch.guild_members_chunk = _guild_members_chunk; 
}

void cluster::on_message_reaction_remove (std::function<void(const message_reaction_remove_t& _event)> _message_reaction_remove) {
	this->dispatch.message_reaction_remove = _message_reaction_remove; 
}

void cluster::on_guild_create (std::function<void(const guild_create_t& _event)> _guild_create) {
	this->dispatch.guild_create = _guild_create; 
}

void cluster::on_channel_create (std::function<void(const channel_create_t& _event)> _channel_create) {
	this->dispatch.channel_create = _channel_create; 
}

void cluster::on_message_reaction_remove_emoji (std::function<void(const message_reaction_remove_emoji_t& _event)> _message_reaction_remove_emoji) {
	this->dispatch.message_reaction_remove_emoji = _message_reaction_remove_emoji; 
}

void cluster::on_message_delete_bulk (std::function<void(const message_delete_bulk_t& _event)> _message_delete_bulk) {
	this->dispatch.message_delete_bulk = _message_delete_bulk; 
}

void cluster::on_guild_role_update (std::function<void(const guild_role_update_t& _event)> _guild_role_update) {
	this->dispatch.guild_role_update = _guild_role_update; 
}

void cluster::on_guild_role_delete (std::function<void(const guild_role_delete_t& _event)> _guild_role_delete) {
	this->dispatch.guild_role_delete = _guild_role_delete; 
}

void cluster::on_channel_pins_update (std::function<void(const channel_pins_update_t& _event)> _channel_pins_update) {
	this->dispatch.channel_pins_update = _channel_pins_update; 
}

void cluster::on_message_reaction_remove_all (std::function<void(const message_reaction_remove_all_t& _event)> _message_reaction_remove_all) {
	this->dispatch.message_reaction_remove_all = _message_reaction_remove_all; 
}

void cluster::on_voice_server_update (std::function<void(const voice_server_update_t& _event)> _voice_server_update) {
	this->dispatch.voice_server_update = _voice_server_update; 
}

void cluster::on_guild_emojis_update (std::function<void(const guild_emojis_update_t& _event)> _guild_emojis_update) {
	this->dispatch.guild_emojis_update = _guild_emojis_update; 
}

void cluster::on_presence_update (std::function<void(const presence_update_t& _event)> _presence_update) {
	this->dispatch.presence_update = _presence_update; 
}

void cluster::on_webhooks_update (std::function<void(const webhooks_update_t& _event)> _webhooks_update) {
	this->dispatch.webhooks_update = _webhooks_update; 
}

void cluster::on_guild_member_add (std::function<void(const guild_member_add_t& _event)> _guild_member_add) {
	this->dispatch.guild_member_add = _guild_member_add; 
}

void cluster::on_invite_delete (std::function<void(const invite_delete_t& _event)> _invite_delete) {
	this->dispatch.invite_delete = _invite_delete; 
}

void cluster::on_guild_update (std::function<void(const guild_update_t& _event)> _guild_update) {
	this->dispatch.guild_update = _guild_update; 
}

void cluster::on_guild_integrations_update (std::function<void(const guild_integrations_update_t& _event)> _guild_integrations_update) {
	this->dispatch.guild_integrations_update = _guild_integrations_update; 
}

void cluster::on_guild_member_update (std::function<void(const guild_member_update_t& _event)> _guild_member_update) {
	this->dispatch.guild_member_update = _guild_member_update; 
}

void cluster::on_application_command_update (std::function<void(const application_command_update_t& _event)> _application_command_update) {
	this->dispatch.application_command_update = _application_command_update; 
}

void cluster::on_invite_create (std::function<void(const invite_create_t& _event)> _invite_create) {
	this->dispatch.invite_create = _invite_create; 
}

void cluster::on_message_update (std::function<void(const message_update_t& _event)> _message_update) {
	this->dispatch.message_update = _message_update; 
}

void cluster::on_user_update (std::function<void(const user_update_t& _event)> _user_update) {
	this->dispatch.user_update = _user_update; 
}

void cluster::on_message_create (std::function<void(const message_create_t& _event)> _message_create) {
	this->dispatch.message_create = _message_create; 
}

void cluster::on_guild_ban_add (std::function<void(const guild_ban_add_t& _event)> _guild_ban_add) {
	this->dispatch.guild_ban_add = _guild_ban_add; 
}


};
