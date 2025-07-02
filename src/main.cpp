#include <vk_engine.h>

int main(int argc, char* argv[])
{
	VulkanEngine engine;
    fmt::println("Engine created");

	engine.init();	
    fmt::println("Engine initialized, start running");
	
	engine.run();
    fmt::println("Engine finished running");

	engine.cleanup();
    fmt::println("Engine cleaned up");

	return 0;
}
