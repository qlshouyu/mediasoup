#define MS_CLASS "mediasoup-worker"
// #define MS_LOG_DEV_LEVEL 3

#include "MediaSoupErrors.hpp"
#include "lib.hpp"
#include <cstdlib> // std::_Exit()
#include <string>

static constexpr int ConsumerChannelFd{ 3 };
static constexpr int ProducerChannelFd{ 4 };
static constexpr int PayloadConsumerChannelFd{ 5 };
static constexpr int PayloadProducerChannelFd{ 6 };

// void readFnCall(uint8_t* msg, uint32_t msgLen, size_t ctx){
// 	std::cout<<"readFnCall:"<<msg<<std::endl;
// }

// ChannelReadFreeFn readFn(
//   uint8_t** msg /* message */,
//   uint32_t* msgLen /* messageLen */,
//   size_t* msgCtx /* messageCtx */,
//   // This is `uv_async_t` handle that can be called later with `uv_async_send()`
//   // when there is more data to read.
//   const void*  handle/* handle */,
//   ChannelReadCtx ctx /* ctx */
// ){
// 	std::cout<<"readFn:"<<msg<<std::endl;
	
// 	flatbuffers::FlatBufferBuilder builder;


// 	auto request= FBS::CreateRequest(builder,123456,
// 		FBS::Request::Method::WORKER_CREATE_ROUTER,
// 		builder.CreateString("handler_id1"),FBS::Request::Body::Worker_CreateRouterRequest);


// 	ChannelReadFreeFn fun=readFnCall;
// 	std::cout<<"===== readFn ==="<<std::endl;
// 	return nullptr;
// }

// void writeFn(const uint8_t* msg /* message */, uint32_t msgLen/* messageLen */, ChannelWriteCtx ctx/* ctx */){
// 	std::cout<<"writefn:"<<msg<<std::endl;
// }

int main(int argc, char* argv[])
{
	// Ensure we are called by our Node library.
	if (!std::getenv("MEDIASOUP_VERSION"))
	{
		MS_ERROR_STD("you don't seem to be my real father!");

		// 41 is a custom exit code to notify about "missing MEDIASOUP_VERSION" env.
		std::_Exit(41);
	}

	const std::string version = std::getenv("MEDIASOUP_VERSION");

	auto statusCode = mediasoup_worker_run(
	  argc,
	  argv,
	  "3.0",
	  ConsumerChannelFd,
	  ProducerChannelFd,
	  PayloadConsumerChannelFd,
	  PayloadProducerChannelFd,
	  nullptr,
	  nullptr,
	  nullptr,
	  nullptr);
	// ChannelReadCtx rCtx=nullptr;
	// ChannelWriteCtx wCtx=nullptr;
	// auto statusCode = mediasoup_worker_run(
	//   argc,
	//   argv,
	//   "3.0",
	//   0,
	//   0,
	//   0,
	//   0,
	//   readFn,
	//   rCtx,
	//   writeFn,
	//   wCtx);

	std::_Exit(statusCode);
}
