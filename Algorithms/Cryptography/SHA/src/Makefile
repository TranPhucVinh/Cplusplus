aws_s3_bucket:
	g++ aws_s3_bucket.cpp functions.cpp msg_padding_parsing.cpp sha256.cpp

sha_1_str:
	g++ sha_1_str.cpp functions.cpp msg_padding_parsing.cpp sha1.cpp

sha_256_str:
	g++ sha_256_str.cpp functions.cpp msg_padding_parsing.cpp sha256.cpp

sha_lib:
	g++ -c functions.cpp msg_padding_parsing.cpp sha1.cpp sha256.cpp
	ar r libsha.a functions.o msg_padding_parsing.o sha1.o sha256.o
	rm *.o

hmac_sha_256:
	g++ hmac_sha_256.cpp functions.cpp msg_padding_parsing.cpp sha256.cpp

# Add unit test code to unit_test.cpp
unit_test:
	g++ unit_test.cpp functions.cpp msg_padding_parsing.cpp sha256.cpp