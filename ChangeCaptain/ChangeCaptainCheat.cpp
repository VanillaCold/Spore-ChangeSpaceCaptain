#include "stdafx.h"
#include "ChangeCaptainCheat.h"

ChangeCaptain::ChangeCaptain()
{
}


ChangeCaptain::~ChangeCaptain()
{
}


void ChangeCaptain::ParseLine(const ArgScript::Line& line)
{
	// This method is called when your cheat is invoked.
	// Put your cheat code here.	Simulator::GetPlayerEmpire()->mCaptainKey;
	if (Simulator::IsSpaceGame())
	{
		Sporepedia::ShopperRequest request(this);
		request.shopperID = id("AdventurersShopper");
		request.Show(request);
	}
	else { App::ConsolePrintF("This cheat can only be used in the Space Stage."); }
}

const char* ChangeCaptain::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "Changes your captain in the space stage.";
	}
	else {
		return "ChangeCaptain: This cheat lets you select any captain for use as your captain in the space stage, as long as it's eligible for use in free-play.";
	}
}

void ChangeCaptain::OnShopperAccept(const ResourceKey& selection)
{
	Simulator::GetPlayerEmpire()->mCaptainKey = selection;
}
