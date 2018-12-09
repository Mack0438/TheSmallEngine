#pragma once

#ifndef __VulkanSetup_H_INCLUDED__
#define __VulkanSetup_H_INCLUDED__

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <vector>
#include <iostream>
#include <stdexcept>
#include <functional>
#include <cstdlib>

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

class VulkanSetup
{
public:
	VulkanSetup();
	~VulkanSetup();

	VkInstance createInstance(std::vector<const char*> validationLayers);
	VkDebugUtilsMessengerEXT setupDebugCallback(VkInstance instance);
	static VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pCallback);
	static void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT callback, const VkAllocationCallbacks* pAllocator);
	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);
private:
	bool checkValidationLayerSupport(std::vector<const char*> validationLayers);
	bool compareLayers(std::vector<VkLayerProperties> availableLayers, std::vector<const char*> validationLayers);
	std::vector<const char*> getRequiredExtensions();
};

#endif 