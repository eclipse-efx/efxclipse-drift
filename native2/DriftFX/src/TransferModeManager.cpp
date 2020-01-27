#include "TransferModeManager.h"

#include <utils/Logger.h>
#include <iostream>

using namespace driftfx::internal;

TransferModeImpl::~TransferModeImpl() {
}

TransferModeImpl::TransferModeImpl(std::string name) :
	name(name),
	id(-1) {
	
}

ShareData* TransferModeImpl::CreateShareData(SharedTexture* texture) {
	ShareData* data = texture->CreateShareData();
	data->transferMode = Id();
	return data;
}

TransferModeId TransferModeImpl::Id() {
	return id;
}

void TransferModeImpl::SetId(TransferModeId id) {
	this->id = id;
}

bool TransferModeImpl::isFallback() {
	return false;
}

bool TransferModeImpl::isPlatformDefault() {
	return false;
}

std::string TransferModeImpl::Name() {
	return name;
}



TransferModeManager* TransferModeManager::instance = nullptr;

TransferModeManager::TransferModeManager() :
	transferModes(),
	nextId(0) {

}
TransferModeManager::~TransferModeManager() {

}

TransferModeImpl* TransferModeManager::GetPlatformDefault() {
	std::map<TransferModeId, TransferModeImpl*>::iterator it = transferModes.begin();

	while (it != transferModes.end()) {
		auto mode = it->second;
		if (mode->isPlatformDefault()) {
			return mode;
		}
		it++;
	}

	return nullptr;
}

TransferModeImpl* TransferModeManager::GetFallback() {
	std::map<TransferModeId, TransferModeImpl*>::iterator it = transferModes.begin();

	while (it != transferModes.end()) {
		auto mode = it->second;
		if (mode->isFallback()) {
			return mode;
		}
		it++;
	}

	return nullptr;
}

TransferModeManager* TransferModeManager::Instance() {
	if (instance == nullptr) {
		instance = new TransferModeManager();
	}
	return instance;
}

TransferModeId TransferModeManager::RegisterTransferMode(TransferModeImpl* transferMode) {
	TransferModeId id = nextId++;
	LogInfo("Registering TransferMode Instance '" << transferMode->Name() << "' as " << id);
	transferModes[id] = transferMode;
	transferMode->SetId(id);
	return id;
}

TransferModeImpl* TransferModeManager::GetTransferMode(TransferModeId id)
{
	return transferModes[id];
}


std::list<TransferModeImpl*> TransferModeManager::GetAvailableModes() {
	std::list<TransferModeImpl*> result;
	for (std::map<TransferModeId, TransferModeImpl*>::iterator it = transferModes.begin(); it != transferModes.end(); it++) {
		result.push_back(it->second);
	}
	return result;
}


