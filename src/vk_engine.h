﻿// vulkan_guide.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <vk_types.h>

struct FrameData {
    VkCommandPool _commandPool;
    VkCommandBuffer _mainCommandBuffer;
    
    VkFence _renderFence;
};

constexpr unsigned int FRAME_OVERLAP = 2;

class VulkanEngine {
public:

	bool _isInitialized{ false };
	int _frameNumber {0};
	bool stop_rendering{ false };
	VkExtent2D _windowExtent{ 1700 , 900 };

	struct SDL_Window* _window{ nullptr };

	static VulkanEngine& Get();
    
    VkInstance _instance;
    VkDebugUtilsMessengerEXT _debug_messenger;
    VkPhysicalDevice _chosenGPU;
    VkDevice _device;
    VkSurfaceKHR _surface;
    
    VkSwapchainKHR _swapchain;
    VkFormat _swapchainImageFormat;
    
    FrameData _frames[FRAME_OVERLAP];
    
    FrameData& get_current_frame() { return _frames[_frameNumber % FRAME_OVERLAP]; };
    
    VkQueue _graphicsQueue;
    uint32_t _graphicsQueueFamily;
    
    uint32_t swapchainImageCount = 0;
    std::vector<VkSemaphore> _swapchainSemaphores;
    std::vector<VkSemaphore> _renderSemaphores;
    
    std::vector<VkImage> _swapchainImages;
    std::vector<VkImageView> _swapchainImageViews;
    VkExtent2D _swapchainExtent;

	//initializes everything in the engine
	void init();

	//shuts down the engine
	void cleanup();

	//draw loop
	void draw();

	//run main loop
	void run();
    
private:
    void init_vulkan();
    void init_swapchain();
    void init_commands();
    void init_sync_structures();
    
    void create_swapchain(uint32_t width, uint32_t height);
    void destroy_swapchain();
};
