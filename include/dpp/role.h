#pragma once

#include <dpp/json_fwd.hpp>

namespace dpp {

enum role_flags {
	r_hoist =		0b00000001,
	r_managed =		0b00000010,
	r_mentionable =		0b00000100,
	r_premium_subscriber =	0b00001000,
};

enum role_permissions {
	p_create_instant_invite	=	0x00000001,	/* allows creation of instant invites */
	p_kick_members		=	0x00000002,	/* allows kicking members */
	p_ban_members		=	0x00000004,	/* allows banning members */
	p_administrator		=	0x00000008,	/* allows all permissions and bypasses channel permission overwrites */
	p_manage_channels	=	0x00000010,	/* allows management and editing of channels */
	p_manage_guild		=	0x00000020,	/* allows management and editing of the guild */
	p_add_reactions		=	0x00000040,	/* allows for the addition of reactions to messages */
	p_view_audit_log	=	0x00000080,	/* allows for viewing of audit logs */
	p_priority_speaker	=	0x00000100,	/* allows for using priority speaker in a voice channel */
	p_stream		=	0x00000200,	/* allows the user to go live */
	p_view_channel		=	0x00000400,	/* allows guild members to view a channel, which includes reading messages in text channels */
	p_send_messages		=	0x00000800,	/* allows for sending messages in a channel */
	p_send_tts_messages	=	0x00001000,	/* allows for sending of /tts messages */
	p_manage_messages	=	0x00002000,	/* allows for deletion of other users messages */
	p_embed_links		=	0x00004000,	/* links sent by users with this permission will be auto-embedded */
	p_attach_files		=	0x00008000,	/* allows for uploading images and files */
	p_read_message_history	=	0x00010000,	/* allows for reading of message history */
	p_mention_everyone	=	0x00020000,	/* allows for using the @everyone and the @here tag to notify users in a channel */
	p_use_external_emojis	=	0x00040000,	/* allows the usage of custom emojis from other servers */
	p_view_guild_insights	=	0x00080000,	/* allows for viewing guild insights */
	p_connect		=	0x00100000,	/* allows for joining of a voice channel */
	p_speak			=	0x00200000,	/* allows for speaking in a voice channel */
	p_mute_members		=	0x00400000,	/* allows for muting members in a voice channel */
	p_deafen_members	=	0x00800000,	/* allows for deafening of members in a voice channel */
	p_move_members		=	0x01000000,	/* allows for moving of members between voice channels */
	p_use_vad		=	0x02000000,	/* allows for using voice-activity-detection in a voice channel */
	p_change_nickname	=	0x04000000,	/* allows for modification of own nickname */
	p_manage_nicknames	=	0x08000000,	/* allows for modification of other users nicknames */
	p_manage_roles		=	0x10000000,	/* allows management and editing of roles */
	p_manage_webhooks	=	0x20000000,	/* allows management and editing of webhooks */
	p_manage_emojis		=	0x40000000	/* allows management and editing of emojis */
};

class role : public managed {
public:
	std::string name;
	uint32_t colour;
	uint8_t position;
	uint32_t permissions;
	uint8_t flags;
	snowflake integration_id;
	snowflake bot_id;

	role();
	~role();
	void fill_from_json(nlohmann::json* j);

	bool has_create_instant_invite();
	bool has_kick_members();
	bool has_ban_members();
	bool has_administrator();
	bool has_manage_channels();
	bool has_manage_guild();
	bool has_add_reactions();
	bool has_view_audit_log();
	bool has_priority_speaker();
	bool has_stream();
	bool has_view_channel();
	bool has_send_messages();
	bool has_send_tts_messages();
	bool has_manage_messages();
	bool has_embed_links();
	bool has_attach_files();
	bool has_read_message_history();
	bool has_mention_everyone();
	bool has_use_external_emojis();
	bool has_view_guild_insights();
	bool has_connect();
	bool has_speak();
	bool has_mute_members();
	bool has_deafen_members();
	bool has_move_members();
	bool has_use_vad();
	bool has_change_nickname();
	bool has_manage_nicknames();
	bool has_manage_roles();
	bool has_manage_webhooks();
	bool has_manage_emojis();
};

typedef std::unordered_map<snowflake, role*> role_map;

};
