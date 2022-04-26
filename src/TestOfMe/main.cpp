/*!
 * \file WtBtRunner.cpp
 * \project	WonderTrader
 *
 * \author Wesley
 * \date 2020/03/30
 * 
 * \brief 
 */
#include "../WtBtCore/HisDataReplayer.h"
#include "../WtBtCore/CtaMocker.h"
#include "../WtBtCore/ExecMocker.h"
#include "../WtBtCore/HftMocker.h"
#include "../WtBtCore/SelMocker.h"
#include "../WtBtCore/UftMocker.h"
#include "../WtBtCore/WtHelper.h"

#include "../WTSTools/WTSLogger.h"
#include "../WTSUtils/SignalHook.hpp"

#include "../WTSUtils/WTSCfgLoader.h"
#include "../Includes/WTSVariant.hpp"
#include "../Share/StdUtils.hpp"

#ifdef _MSC_VER
#include "../Common/mdump.h"
#endif
#include <iostream>
int main()
{
	std::string filename = "configbt.json";
	if(!StdFile::exists(filename.c_str()))
		filename = "configbt.yaml";

	WTSVariant* cfg = WTSCfgLoader::load_from_file(filename.c_str(), true);
	if (cfg == NULL)
	{
		WTSLogger::info_f("Loading configuration file {} failed", filename);
		return -1;
	}

	WTSVariant* cfgEnv = cfg->get("env");
	// const char* mode = cfgEnv->getCString("mocker");
    const char* mode = cfg->get("env")->getCString("mocker");
	int32_t slippage = cfg->get("env")->getInt32("slippage");

    std::cout<<"mode: "<<mode<<" slippage: "<<slippage<<std::endl;
}
