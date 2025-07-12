#include <vulkan/vulkan.h>

#pragma once

namespace vkutil {
    void transition_image(VkCommandBuffer cmd, VkImage image, VkImageLayout currentLayout, VkImageLayout newLayout);
};