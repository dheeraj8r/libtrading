#ifndef LIBTRADING_FAST_SESSION_H
#define LIBTRADING_FAST_SESSION_H

#include <libtrading/proto/fast_message.h>

#include <libtrading/buffer.h>

#define	FAST_RECV_BUFFER_SIZE	4096UL

struct fast_message;

struct fast_session {
	u64			last_tid;
	int			sockfd;

	struct buffer		*rx_buffer;

	int			nr_messages;
	struct fast_message	*rx_messages;
};

bool fast_session_message_add(struct fast_session *self, struct fast_message *msg);
struct fast_message *fast_session_recv(struct fast_session *self, int flags);
struct fast_session *fast_session_new(int sockfd);
void fast_session_free(struct fast_session *self);

#endif
