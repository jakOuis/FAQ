.DEFAULT_GOAL=all

hook: faq_hook.proto
	protoc -I . --grpc_out=dllexport_decl=FAQ_PROTOS:. --experimental_allow_proto3_optional --plugin=protoc-gen-grpc="E:\protoc-3.7.0-win64\bin\grpc_cpp_plugin.exe" $<
	protoc -I . --experimental_allow_proto3_optional --cpp_out=dllexport_decl=FAQ_PROTOS:. $^

client: faq_client.proto
	protoc -I . --grpc_out=dllexport_decl=FAQ_PROTOS:. --experimental_allow_proto3_optional --plugin=protoc-gen-grpc="E:\protoc-3.7.0-win64\bin\grpc_cpp_plugin.exe" $<
	protoc -I . --experimental_allow_proto3_optional --cpp_out=dllexport_decl=FAQ_PROTOS:. $^

all: hook client