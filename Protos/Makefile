all: faq_hook.proto
	protoc -I ./ --grpc_out=. --plugin=protoc-gen-grpc="E:\protoc-3.7.0-win64\bin\grpc_cpp_plugin.exe" $<
	protoc -I . --cpp_out=. $^