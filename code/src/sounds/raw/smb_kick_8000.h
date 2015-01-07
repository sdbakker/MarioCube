#ifndef __smb_kick_H__
#define __smb_kick_H__

// smb_kick sound made by wav2c (adapted by simon@simbits.nl)

#define smb_kick_sampleRate 8000
#define smb_kick_length 1448

#define __smb_kick_data0 \
0x81, 0x81, 0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x81, 0x81, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x81, \
0x80, 0x80, 0x80, 0x81, 0x80, 0x7f, 0x7f, 0x7f, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x81, 0x81, 0x81, 0x81, 0x80, \
0x80, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x80, 0x80, 0x80, 0x81, 0x81, 0x80, 0x80, 0x80, 0x80, 0x7f, 0x7f, 0x80, \
0x80, 0x80, 0x80, 0x80, 0x80, 0x81, 0x81, 0x81, 0x80, 0x7f, 0x7f, 0x80, 0x80, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, \
0x7f, 0x7f, 0x7f, 0x80, 0x80, 0x7f, 0x7f, 0x80, 0x81, 0x81, 0x81, 0x82, 0x81, 0x80, 0x80, 0x80, 0x7f, 0x7f, 0x80, 0x80, \
0x7f, 0x7f, 0x7f, 0x80, 0x80, 0x81, 0x81, 0x80, 0x7f, 0x7f, 0x80, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x80, 0x80, 0x80, \
0x81, 0x81, 0x82, 0x81, 0x81, 0x7f, 0x80, 0x7f, 0x80, 0x7f, 0x80, 0x7e, 0x80, 0x7f, 0x80, 0x7f, 0x7e, 0x80, 0x7e, 0xd1, \
0xef, 0xde, 0xe4, 0xd6, 0xdb, 0xcd, 0xd8, 0xb2, 0x5f, 0x63, 0x63, 0x62, 0x65, 0x63, 0x6c, 0x62, 0xad, 0xdc, 0xc9, 0xd0, \
0xc5, 0xc9, 0xbe, 0xc4, 0xb0, 0x58, 0x51, 0x57, 0x53, 0x5a, 0x54, 0x5f, 0x52, 0x8f, 0xcf, 0xbf, 0xc4, 0xbb, 0xbd, 0xb8, \
0xb9, 0xb2, 0x5a, 0x43, 0x51, 0x4a, 0x56, 0x4f, 0x5b, 0x4d, 0x7b, 0xc7, 0xbd, 0xbe, 0xbb, 0xb8, 0xb8, 0xb1, 0xb6, 0x65, \
0x3d, 0x4e, 0x46, 0x52, 0x4a, 0x57, 0x48, 0x9c, 0xc2, 0xb6, 0xb7, 0xb5, 0xb2, 0xb5, 0x9d, 0x41, 0x4a, 0x46, 0x50, 0x4b, \
0x57, 0x4b, 0x9a, 0xc5, 0xb6, 0xb9, 0xb4, 0xb3, 0xb3, 0xa0, 0x42, 0x4b, 0x45, 0x4f, 0x49, 0x56, 0x48, 0x97, 0xc3, 0xb5, \
0xb9, 0xb3, 0xb0, 0xb0, 0x9e, 0x40, 0x49, 0x45, 0x50, 0x4a, 0x57, 0x49, 0x97, 0xc4, 0xb7, 0xb9, 0xb5, 0xb1, 0xb4, 0xa1, \
0x45, 0x48, 0x4a, 0x4e, 0x4d, 0x52, 0x4a, 0x8e, 0xc9, 0xa9, 0x57, 0x49, 0x55, 0x50, 0x59, 0x54, 0x5b, 0x57, 0x5e, 0x5b, \
0x61, 0x60, 0x64, 0x63, 0x66, 0x65, 0x67, 0x67, 0x69, 0x6a, 0x6b, 0x6c, 0x6c, 0x6d, 0x6e, 0x70, 0x70, 0x72, 0x72, 0x73, \
0x73, 0x74, 0x74, 0x75, 0x75, 0x75, 0x74, 0x75, 0x75, 0x75, 0x75, 0x75, 0x75, 0x76, 0x77, 0x77, 0x77, 0x77, 0x77, 0x78, \
0x79, 0x79, 0x7a, 0x7a, 0x7b, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7d, 0x7e, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, \
0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7e, 0x7e, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x80, 0x80, 0x80, \
0x80, 0x80, 0x80, 0x80, 0x80, 0x7f, 0x7f, 0x7f, 0x80, 0x81, 0x81, 0x81, 0x81, 0x80, 0x7f, 0x7f, 0x7f, 0x80, 0x7f, 0x7e, \
0x7d, 0x7d, 0x7d, 0x7d, 0x7d, 0x7e, 0x7f, 0x80, 0x80, 0x80, 0x7f, 0x7e, 0x7e, 0x7e, 0x7f, 0x80, 0x80, 0x80, 0x80, 0x80, \
0x81, 0x82, 0x82, 0x81, 0x81, 0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x81, 0x82, 0x81, 0x80, 0x80, 0x80, 0x80, 0x80, \
0x80, 0x7f, 0x7e, 0x7f, 0x80, 0x80, 0x7f, 0x7e, 0x7e, 0x7e, 0x7f, 0x7f, 0x7f, 0x7f, 0x80, 0x80, 0x80, 0x81, 0x81, 0x80, \
0x80, 0x80, 0x80, 0x80, 0x80, 0x7f, 0x7f, 0x80, 0x81, 0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, \
0x80, 0x80, 0x80, 0x80, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x80, 0x80, 0x81, 0x80, 0x7f, 0x7f, 0x7f, \
0x7e, 0x7d, 0x7d, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7f, 0x80, 0x7f, \
0x7e, 0x7f, 0x80, 0x81, 0x82, 0x81, 0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x81, 0x81, 0x81, 0x81, 0x80, 0x7f, 0x7f, \
0x7f, 0x80, 0x81, 0x81, 0x80, 0x80, 0x80, 0x81, 0x81, 0x82, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x82, 0x82, \
0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x81, 0x80, 0x80, 0x81, 0x81, 0x80, 0x80, 0x80, 0x7f, 0x7e, 0x7f, 0x80, 0x81, 0x81, \
0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x7f, 0x7f, 0x80, 0x80, 0x80, 0x81, \
0x82, 0x82, 0x82, 0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x7f, 0x80, 0x80, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, \
0x80, 0x81, 0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, \
0x80, 0x7f, 0x7f, 0x80, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, \
0x80, 0x81, 0x82, 0x82, 0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x81, 0x81, 0x81, 0x81, 0x81, 0x82, 0x81, 0x80, 0x80, 0x81, \
0x81, 0x81, 0x81, 0x80, 0x7f, 0x7f, 0x80, 0x80, 0x80, 0x80, 0x80, 0x7f, 0x7e, 0x7e, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, \
0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x80, 0x80, 0x7f, 0x7f, 0x7f, 0x7f, 0x80, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, \
0x80, 0x7f, 0x80, 0x81, 0x81, 0x81, 0x80, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7e, 0x7f, 0x7f, 0x80, 0x80, 0x80, 0x80, 0x80, \
0x80, 0x80, 0x80, 0x7f, 0x7f, 0x7f, 0x7e, 0x7d, 0x7d, 0x7d, 0x7e, 0x7e, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7e, 0x7d, \
0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x80, 0x80, 0x80, 0x80, 0x80, \
0x80, 0x80, 0x80, 0x7f, 0x7e, 0x7e, 0x7f, 0x7f, 0x7f, 0x7f, 0x80, 0x81, 0x82, 0x81, 0x81, 0x81, 0x80, 0x80, 0x80, 0x80, \
0x80, 0x80, 0x80, 0x80, 0x81, 0x82, 0x81, 0x80, 0x80, 0x80, 0x80, 0x7f, 0x7f, 0x7f, 0x7f, 0x7e, 0x7e, 0x7e, 0x7e, 0x7f, \
0x80, 0x80, 0x7f, 0x7f, 0x80, 0x81, 0x81, 0x81, 0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x7f, 0x7f, 0x80, 0x80, 0x80, 0x7f, \
0x7f, 0x80, 0x81, 0x81, 0x80, 0x7f, 0x7e, 0x7f, 0x80, 0x80, 0x7f, 0x80, 0x81, 0x81, 0x80, 0x7f, 0x7f, 0x7f, 0x7f, 0x80, \
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x81, 0x81, 0x80, 0x80, 0x80, 0x80, 0x7f, 0x7f, 0x7f, 0x80, 0x81, 0x81, 0x81, \
0x81, 0x81, 0x81, 0x80, 0x80, 0x81, 0x82, 0x82, 0x81, 0x81, 0x80, 0x80, 0x81, 0x82, 0x82, 0x81, 0x81, 0x82, 0x82, 0x81, \
0x81, 0x82, 0x82, 0x82, 0x82, 0x82, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x80, 0x81, 0x81, 0x81, 0x80, 0x80, \
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x7f, 0x80, 0x80, 0x81, 0x81, 0x82, 0x80, 0x80, 0x7f, 0x80, 0x80, 0x81, 0x80, \
0x81, 0x80, 0x81, 0x80, 0x7f, 0x7f, 0x80, 0x81, 0x7f, 0x80, 0x7e, 0x81, 0x7d, 0x85, 0x79, 0xa7, 0xf1, 0xe1, 0xe4, 0xd6, \
0x78, 0x6b, 0x6f, 0x71, 0x6d, 0x87, 0xe1, 0xd3, 0xd9, 0xcb, 0xd7, 0x9c, 0x55, 0x68, 0x5d, 0x6a, 0x5c, 0xaf, 0xd4, 0xc6, \
0xc8, 0xc0, 0xbe, 0x5e, 0x53, 0x57, 0x5a, 0x57, 0x6f, 0xca, 0xbf, 0xc4, 0xb7, 0xc3, 0x8c, 0x44, 0x57, 0x4c, 0x59, 0x4c, \
0x9e, 0xc9, 0xba, 0xbf, 0xb6, 0xb7, 0x58, 0x4b, 0x50, 0x53, 0x51, 0x66, 0xc4, 0xbc, 0xc1, 0xb5, 0xc0, 0x8d, 0x41, 0x53, \
0x49, 0x56, 0x48, 0x97, 0xc5, 0xb5, 0xbb, 0xb2, 0xb6, 0x57, 0x45, 0x4b, 0x4d, 0x4c, 0x5e, 0xbd, 0xb7, 0xbb, 0xb0, 0xbb, \
0x8c, 0x3d, 0x4e, 0x44, 0x52, 0x44, 0x90, 0xc3, 0xb3, 0xba, 0xb0, 0xb6, 0x59, 0x45, 0x4d, 0x4e, 0x4f, 0x5c, 0xbb, 0xb7, \
0xba, 0xaf, 0xb8, 0x8c, 0x3b, 0x4c, 0x44, 0x52, 0x45, 0x8d, 0xc4, 0xb1, 0xb9, 0xae, 0xb7, 0x5c, 0x44, 0x4d, 0x4c, 0x4e, \
0x5a, 0xbb, 0xb9, 0xbb, 0xb1, 0xbb, 0x90, 0x3f, 0x4b, 0x47, 0x4d, 0x4d, 0x51, 0x51, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, \
0x5f, 0x61, 0x61, 0x62, 0x62, 0x63, 0x63, 0x65, 0x66, 0x68, 0x69, 0x6b, 0x6b, 0x6c, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, \
0x72, 0x72, 0x72, 0x73, 0x74, 0x75, 0x75, 0x75, 0x76, 0x77, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x79, 0x7a, 0x7a, 0x7a, \
0x7b, 0x7c, 0x7c, 0x7c, 0x7d, 0x7e, 0x7e, 0x7e, 0x7e, 0x7d, 0x7d, 0x7e, 0x7e, 0x7d, 0x7d, 0x7d, 0x7d, 0x7d, 0x7d, 0x7d, \
0x7d, 0x7c, 0x7d, 0x7e, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7e, 0x7d, 0x7e, 0x7f, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x7f, \
0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7f, 0x80, 0x80, 0x80, 0x80, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, \
0x81, 0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x7f, 0x7f, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x81, 0x81, 0x80, \
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x81, 0x81, 0x80, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, \
0x80, 0x80, 0x80, 0x80, 0x80, 0x81, 0x82, 0x82, 0x81, 0x81, 0x80, 0x80, 0x81, 0x81, 0x81, 0x82, 0x82, 0x81, 0x81, 0x82, \
0x82, 0x82, 0x82, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x80, 0x80, 0x81, 0x81, 0x80, 0x80, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, \
0x7f, 0x7f, 0x80, 0x80, 0x80, 0x80, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x80, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, \
0x81, 0x81, 0x81, 0x81, 0x80, 0x7f, 0x7e, 0x7e, 0x7e, 0x7f, 0x80, 0x80, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7e, 0x7e, 0x7e, \
0x7e, 0x7e, 0x7f, 0x7f, 0x7f, 0x80, 0x81, 0x80, 0x80, 0x80, 0x80, 0x7f, 0x7f, 0x80, 0x81, 0x82, 0x82, 0x81, 0x81, 0x81, \
0x81, 0x80, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x80, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7e, 0x7e, 0x7f, 0x80, 0x7f, 0x7e, \
0x7e, 0x7f, 0x80, 0x81, 0x81, 0x81, 0x82, 0x82, 0x81, 0x80, 0x80, 0x81, 0x81, 0x81, 0x82, 0x82, 0x81, 0x80, 0x81, 0x82, \
0x83, 0x83, 0x83, 0x82, 0x81, 0x80, 0x7f, 0x7f, 0x7f, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x81, \
0x81, 0x80, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x80, 0x80, 0x80, 0x80, 0x81, 0x81, 0x81, 0x80, 0x7f, 0x7f, 0x80, 0x81, \
0x81, 0x80, 0x80, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x7f, \
0x7e, 0x7e, 0x7e, 0x7e, 0x7d, 0x7d, 0x7d, 0x7d, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, \
0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 

const uint8_t smb_kick_data0[] PROGMEM = { __smb_kick_data0 };

#endif /* __smb_kick_H__ */
