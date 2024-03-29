#ifndef _QBASE64_H
#define _QBASE64_H

#define QBASE64_MAX_DEFAULT_SIZE 1000

// Function to Calculate the Encoding Length from plain text length
#define QBASE64_ENC_SIZECALC(X) ((X + 2 - ((X + 2) % 3)) / 3 * 4)

// Error Code for All is Fine
#define QBASE64_STATUS_OK 0

// Error Code for Insufficient size or decoded size error.
#define RABSE64_STATUS_SIZE 1

// Error caused due to Invalid format
#define QBASE64_STATUS_FORMAT 2

/* base64_alphabet:
 *      Description: Base64 alphabet table, a mapping between integers
 *                   and base64 digits
 *      Notes: This is an extern here but is defined in Base64.c
 */
extern const char base64_alphabet[];

/* base64_encode:
 *      Description:
 *          Encode a string of characters as base64
 *      Parameters:
 *          output: the output buffer for the encoding, stores the encoded string
 *          input: the input buffer for the encoding, stores the binary to be encoded
 *          inputLen: the length of the input buffer, in bytes
 *      Return value:
 *          Returns the length of the encoded string
 *      Requirements:
 *          1. output must not be null or empty
 *          2. input must not be null
 *          3. inputLen must be greater than or equal to 0
 */
size_t QBase64_encode(char *output, char *input, size_t inputLen);

/* base64_decode:
 *      Description:
 *          Decode a base64 encoded string into bytes
 *      Parameters:
 *          output: the output buffer for the decoding,
 *                  stores the decoded binary
 *          input: the input buffer for the decoding,
 *                 stores the base64 string to be decoded
 *          inputLen: the length of the input buffer, in bytes
 *      Return value:
 *          Returns the length of the decoded string
 *      Requirements:
 *          1. output must not be null or empty
 *          2. input must not be null
 *          3. inputLen must be greater than or equal to 0
 */
size_t QBase64_decode(char *output, char *input, size_t inputLen);

/* base64_enc_len:
 *      Description:
 *          Returns the length of a base64 encoded string whose decoded
 *          form is inputLen bytes long
 *      Parameters:
 *          inputLen: the length of the decoded string
 *      Return value:
 *          The length of a base64 encoded string whose decoded form
 *          is inputLen bytes long
 *      Requirements:
 *          None
 */
size_t QBase64_enc_len(size_t inputLen);

/* base64_dec_len:
 *      Description:
 *          Returns the length of the decoded form of a
 *          base64 encoded string
 *      Parameters:
 *          input: the base64 encoded string to be measured
 *          inputLen: the length of the base64 encoded string
 *      Return value:
 *          Returns the length of the decoded form of a
 *          base64 encoded string
 *      Requirements:
 *          1. input must not be null
 *          2. input must be greater than or equal to zero
 */
size_t QBase64_dec_len(char *input, size_t inputLen);

/*
 Base 64 Generic Storage class to support Arbitrary size 
 Encoding and Decoding of BASE64
 - sz parameter determines the Plain Text Size that is possible
*/
template<size_t sz>

class QBase64generic {
	
	private:
	// Internal Variable to store the Size of encoding buffer
	size_t MAX_BUF_SIZE = QBASE64_ENC_SIZECALC(sz);
	// Internal Buffer for Encoding and Decoding
	uint8_t buf[QBASE64_ENC_SIZECALC(sz)];
	// Error Storage
	size_t error;
	
	public:
	/**
	 * Function to Encode a Byte Array of fixed length to a Base64 String
	 *
	 * @param data Pointer to the Source Buffer
	 * @param length Source Buffer Length
	 *
	 * @return Error code for the Operation
	 *
	 */
	size_t encode(uint8_t *data, size_t length) {
		size_t o_length = QBase64_enc_len(length);

		// Default We assume there can only be Size Error
		error = RABSE64_STATUS_SIZE;

		// Check Size
		if(o_length <= MAX_BUF_SIZE)
		{
			// Make sure that the Length is Ok for the Output
			if(o_length == QBase64_encode((char *)buf,(char *)data,length))
			{
			  error = QBASE64_STATUS_OK;
			} 
		}
		return error;
	}
	/**
	 * Function to Encode a NULL terminated Array to a Base64 String
	 */
	size_t encode(const char *data) {
		return encode((uint8_t *)data, strlen(data));
	}
	/**
	 * Function to Encode String to a Base64 String
	 */
	size_t encode(String text) {
		return encode((uint8_t *) text.c_str(), text.length());
	}
	/**
	 * Function to Decode the Byte Array with BASE64 encoded String to Normal String
	 *
	 * @param data Pointer to the Source Buffer
	 * @param length Source Buffer Length
	 *
	 * @return Error code for the operation
	 */
	size_t decode(uint8_t *data, size_t length) {
		size_t o_length = QBase64_dec_len((char *)data, length);
		// Default We assume there can only be Size Error
		error = RABSE64_STATUS_SIZE;

		// Check Size
		if(o_length <= MAX_BUF_SIZE)
		{
			// Make sure that the Length is Ok for the Output
			if(o_length == QBase64_decode((char *)buf,(char *)data,length))
			{
			  error = QBASE64_STATUS_OK;
			}
		}
		return error;
	}
	/**
	 * Function to Decode a Null terminated Array containing BASE64 
	 * to a normal String
	 */
	size_t decode(const char *data) {
		return decode((uint8_t *)data, strlen(data));
	}
	/**
	 * Function to Decode a String containing BASE64 to a normal String
	 */
	size_t decode(String text) {
		return decode((uint8_t *) text.c_str(), text.length());
	}
	
	/**
	 * Function to get Result from the earlier operation
	 */
	char * result(void) {
		return (char *)buf;
	}
};

extern QBase64generic<QBASE64_MAX_DEFAULT_SIZE> QBase64;

#endif // _QBASE64_H
