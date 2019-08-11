#ifndef __ENUMS__H
#define __ENUMS__H

enum class EncryptMethods
{
	INVALID_VALUE,
	AES_128_GCM,
	AES_192_GCM,
	AES_256_GCM,
	AES_128_CFB,
	AES_192_CFB,
	AES_256_CFB,
	AES_128_CTR,
	AES_192_CTR,
	AES_256_CTR,
	camellia_128_cfb,
	camellia_192_cfb,
	camellia_256_cfb,
	bf_cfb,
	chacha20_ietf_poly1305,
	xchacha20_ietf_poly1305,
	salsa20,
	chacha20,
	chacha20_ietf,
	rc4_md5,
};

template<typename T>
std::ostream& operator<<(typename std::enable_if<std::is_enum<T>::value, std::ostream>::type& stream, const T& e) 
{
     return stream << static_cast<typename std::underlying_type<T>::type>(e);
}

#endif//__ENUMS__H
