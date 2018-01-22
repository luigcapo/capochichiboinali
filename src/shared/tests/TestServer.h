/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef TESTSERVER_H
#define TESTSERVER_H

#include "server.h"
#include <iostream>
#include <unistd.h>
#include <SFML/Network/Http.hpp>
#include "client/NetworkClient.h"

#include "json/json.h"

void testServer(int port);
void testClient(int port);

#endif /* TESTSERVER_H */

