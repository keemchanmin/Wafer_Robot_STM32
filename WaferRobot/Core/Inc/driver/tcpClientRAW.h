/*
 * tcpClientRAW.h
 *
 *  Created on: Nov 26, 2023
 *      Author: 김찬민
 */

#ifndef INC_TCPCLIENTRAW_H_
#define INC_TCPCLIENTRAW_H_

#include "err.h"
struct tcp_client_struct
{
	u8_t state;             /* current connection state */
	u8_t retries;
  struct tcp_pcb *pcb;    /* pointer on the current tcp_pcb */
  struct pbuf *p;         /* pointer on the received/to be transmitted pbuf */
};


void tcp_client_init(void);
static err_t tcp_client_connected(void *arg, struct tcp_pcb *tpcb, err_t err);
static err_t tcp_client_recv(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err);
static err_t tcp_client_poll(void *arg, struct tcp_pcb *tpcb);
static err_t tcp_client_sent(void *arg, struct tcp_pcb *tpcb, u16_t len);
static void tcp_client_send(struct tcp_pcb *tpcb, struct tcp_client_struct *es);
static void tcp_client_connection_close(struct tcp_pcb *tpcb, struct tcp_client_struct *es);
void  Send2Server(int ID, char robot , char dir);


#endif /* INC_TCPCLIENTRAW_H_ */
