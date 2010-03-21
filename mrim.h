#ifndef MRIM_H
#define MRIM_H

#include "config.h"
#include <glib.h>
#include <purple.h>
#include "proto.h"

#define MRIMPRPL_BALANCER_DEFAULT_PORT 2042
#define MRIMPRPL_BALANCER_DEFAULT_HOST "mrim.mail.ru"


struct _MrimData 
{
    PurpleAccount *account;
    
    struct {
        char *host;
        guint port;
        PurpleProxyConnectData *connect_data;
        gint fd;
        guint read_ih;
    } balancer;

    struct {
        char *host;
        guint port;
        PurpleProxyConnectData *connect_data;
        gint fd;
        guint read_ih;
        guint write_ih;
        PurpleCircBuffer *rx_buf;
        PurpleCircBuffer *tx_buf;
    } server;
};

typedef struct _MrimData MrimData;

const char * mrim_list_icon(PurpleAccount *account, PurpleBuddy *buddy);
const char * mrim_list_emblem(PurpleBuddy *buddy);
char * mrim_status_text(PurpleBuddy *buddy);
void mrim_tooltip_text (PurpleBuddy *buddy, PurpleNotifyUserInfo *nui, gboolean full);
GList * mrim_status_types (PurpleAccount *account);
GList * mrim_blist_node_menu (PurpleBlistNode *node);
void mrim_login(PurpleAccount *account);
void mrim_close(PurpleConnection *gc);
int mrim_send_im(PurpleConnection *gc, const char *who, const char *message, PurpleMessageFlags flags);
void mrim_set_info(PurpleConnection *gc, const char *info);
unsigned int mrim_send_typing(PurpleConnection *gc, const char *name, PurpleTypingState state);
void mrim_get_info(PurpleConnection *gc, const char *who);
void mrim_set_status(PurpleAccount *account, PurpleStatus *status);
void mrim_set_idle(PurpleConnection *gc, int idletime);
void mrim_change_passwd(PurpleConnection *gc, const char *old_pass, const char *new_pass);
void mrim_add_buddy(PurpleConnection *gc, PurpleBuddy *buddy, PurpleGroup *group);
void mrim_remove_buddy(PurpleConnection *gc, PurpleBuddy *buddy, PurpleGroup *group);
void mrim_keepalive(PurpleConnection *gc);
void mrim_group_buddy(PurpleConnection *gc, const char *who, const char *old_group, const char *new_group);
void mrim_rename_group(PurpleConnection *gc, const char *old_name, PurpleGroup *group, GList *moved_buddies);
const char * mrim_normalize(const PurpleAccount *account, const char *who);
void mrim_remove_group(PurpleConnection *gc, PurpleGroup *group);
gboolean mrim_offline_message(const PurpleBuddy *buddy);
gboolean mrim_send_attention(PurpleConnection *gc, const char *username, guint type);
GList * mrim_get_attention_types(PurpleAccount *account);

#endif /*MRIM_H*/