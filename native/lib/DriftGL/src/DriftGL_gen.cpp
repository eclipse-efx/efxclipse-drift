
	#include "DriftGL_gen.h"

	namespace driftgl {
				
		unsigned int GL_DEPTH_BUFFER_BIT = 0x00000100;
		unsigned int GL_STENCIL_BUFFER_BIT = 0x00000400;
		unsigned int GL_COLOR_BUFFER_BIT = 0x00004000;
		unsigned int GL_FALSE = 0;
		unsigned int GL_TRUE = 1;
		unsigned int GL_POINTS = 0x0000;
		unsigned int GL_LINES = 0x0001;
		unsigned int GL_LINE_LOOP = 0x0002;
		unsigned int GL_LINE_STRIP = 0x0003;
		unsigned int GL_TRIANGLES = 0x0004;
		unsigned int GL_TRIANGLE_STRIP = 0x0005;
		unsigned int GL_TRIANGLE_FAN = 0x0006;
		unsigned int GL_NEVER = 0x0200;
		unsigned int GL_LESS = 0x0201;
		unsigned int GL_EQUAL = 0x0202;
		unsigned int GL_LEQUAL = 0x0203;
		unsigned int GL_GREATER = 0x0204;
		unsigned int GL_NOTEQUAL = 0x0205;
		unsigned int GL_GEQUAL = 0x0206;
		unsigned int GL_ALWAYS = 0x0207;
		unsigned int GL_ZERO = 0;
		unsigned int GL_ONE = 1;
		unsigned int GL_SRC_COLOR = 0x0300;
		unsigned int GL_ONE_MINUS_SRC_COLOR = 0x0301;
		unsigned int GL_SRC_ALPHA = 0x0302;
		unsigned int GL_ONE_MINUS_SRC_ALPHA = 0x0303;
		unsigned int GL_DST_ALPHA = 0x0304;
		unsigned int GL_ONE_MINUS_DST_ALPHA = 0x0305;
		unsigned int GL_DST_COLOR = 0x0306;
		unsigned int GL_ONE_MINUS_DST_COLOR = 0x0307;
		unsigned int GL_SRC_ALPHA_SATURATE = 0x0308;
		unsigned int GL_NONE = 0;
		unsigned int GL_FRONT_LEFT = 0x0400;
		unsigned int GL_FRONT_RIGHT = 0x0401;
		unsigned int GL_BACK_LEFT = 0x0402;
		unsigned int GL_BACK_RIGHT = 0x0403;
		unsigned int GL_FRONT = 0x0404;
		unsigned int GL_BACK = 0x0405;
		unsigned int GL_LEFT = 0x0406;
		unsigned int GL_RIGHT = 0x0407;
		unsigned int GL_FRONT_AND_BACK = 0x0408;
		unsigned int GL_NO_ERROR = 0;
		unsigned int GL_INVALID_ENUM = 0x0500;
		unsigned int GL_INVALID_VALUE = 0x0501;
		unsigned int GL_INVALID_OPERATION = 0x0502;
		unsigned int GL_OUT_OF_MEMORY = 0x0505;
		unsigned int GL_CW = 0x0900;
		unsigned int GL_CCW = 0x0901;
		unsigned int GL_POINT_SIZE = 0x0B11;
		unsigned int GL_POINT_SIZE_RANGE = 0x0B12;
		unsigned int GL_POINT_SIZE_GRANULARITY = 0x0B13;
		unsigned int GL_LINE_SMOOTH = 0x0B20;
		unsigned int GL_LINE_WIDTH = 0x0B21;
		unsigned int GL_LINE_WIDTH_RANGE = 0x0B22;
		unsigned int GL_LINE_WIDTH_GRANULARITY = 0x0B23;
		unsigned int GL_POLYGON_MODE = 0x0B40;
		unsigned int GL_POLYGON_SMOOTH = 0x0B41;
		unsigned int GL_CULL_FACE = 0x0B44;
		unsigned int GL_CULL_FACE_MODE = 0x0B45;
		unsigned int GL_FRONT_FACE = 0x0B46;
		unsigned int GL_DEPTH_RANGE = 0x0B70;
		unsigned int GL_DEPTH_TEST = 0x0B71;
		unsigned int GL_DEPTH_WRITEMASK = 0x0B72;
		unsigned int GL_DEPTH_CLEAR_VALUE = 0x0B73;
		unsigned int GL_DEPTH_FUNC = 0x0B74;
		unsigned int GL_STENCIL_TEST = 0x0B90;
		unsigned int GL_STENCIL_CLEAR_VALUE = 0x0B91;
		unsigned int GL_STENCIL_FUNC = 0x0B92;
		unsigned int GL_STENCIL_VALUE_MASK = 0x0B93;
		unsigned int GL_STENCIL_FAIL = 0x0B94;
		unsigned int GL_STENCIL_PASS_DEPTH_FAIL = 0x0B95;
		unsigned int GL_STENCIL_PASS_DEPTH_PASS = 0x0B96;
		unsigned int GL_STENCIL_REF = 0x0B97;
		unsigned int GL_STENCIL_WRITEMASK = 0x0B98;
		unsigned int GL_VIEWPORT = 0x0BA2;
		unsigned int GL_DITHER = 0x0BD0;
		unsigned int GL_BLEND_DST = 0x0BE0;
		unsigned int GL_BLEND_SRC = 0x0BE1;
		unsigned int GL_BLEND = 0x0BE2;
		unsigned int GL_LOGIC_OP_MODE = 0x0BF0;
		unsigned int GL_DRAW_BUFFER = 0x0C01;
		unsigned int GL_READ_BUFFER = 0x0C02;
		unsigned int GL_SCISSOR_BOX = 0x0C10;
		unsigned int GL_SCISSOR_TEST = 0x0C11;
		unsigned int GL_COLOR_CLEAR_VALUE = 0x0C22;
		unsigned int GL_COLOR_WRITEMASK = 0x0C23;
		unsigned int GL_DOUBLEBUFFER = 0x0C32;
		unsigned int GL_STEREO = 0x0C33;
		unsigned int GL_LINE_SMOOTH_HINT = 0x0C52;
		unsigned int GL_POLYGON_SMOOTH_HINT = 0x0C53;
		unsigned int GL_UNPACK_SWAP_BYTES = 0x0CF0;
		unsigned int GL_UNPACK_LSB_FIRST = 0x0CF1;
		unsigned int GL_UNPACK_ROW_LENGTH = 0x0CF2;
		unsigned int GL_UNPACK_SKIP_ROWS = 0x0CF3;
		unsigned int GL_UNPACK_SKIP_PIXELS = 0x0CF4;
		unsigned int GL_UNPACK_ALIGNMENT = 0x0CF5;
		unsigned int GL_PACK_SWAP_BYTES = 0x0D00;
		unsigned int GL_PACK_LSB_FIRST = 0x0D01;
		unsigned int GL_PACK_ROW_LENGTH = 0x0D02;
		unsigned int GL_PACK_SKIP_ROWS = 0x0D03;
		unsigned int GL_PACK_SKIP_PIXELS = 0x0D04;
		unsigned int GL_PACK_ALIGNMENT = 0x0D05;
		unsigned int GL_MAX_TEXTURE_SIZE = 0x0D33;
		unsigned int GL_MAX_VIEWPORT_DIMS = 0x0D3A;
		unsigned int GL_SUBPIXEL_BITS = 0x0D50;
		unsigned int GL_TEXTURE_1D = 0x0DE0;
		unsigned int GL_TEXTURE_2D = 0x0DE1;
		unsigned int GL_TEXTURE_WIDTH = 0x1000;
		unsigned int GL_TEXTURE_HEIGHT = 0x1001;
		unsigned int GL_TEXTURE_BORDER_COLOR = 0x1004;
		unsigned int GL_DONT_CARE = 0x1100;
		unsigned int GL_FASTEST = 0x1101;
		unsigned int GL_NICEST = 0x1102;
		unsigned int GL_BYTE = 0x1400;
		unsigned int GL_UNSIGNED_BYTE = 0x1401;
		unsigned int GL_SHORT = 0x1402;
		unsigned int GL_UNSIGNED_SHORT = 0x1403;
		unsigned int GL_INT = 0x1404;
		unsigned int GL_UNSIGNED_INT = 0x1405;
		unsigned int GL_FLOAT = 0x1406;
		unsigned int GL_CLEAR = 0x1500;
		unsigned int GL_AND = 0x1501;
		unsigned int GL_AND_REVERSE = 0x1502;
		unsigned int GL_COPY = 0x1503;
		unsigned int GL_AND_INVERTED = 0x1504;
		unsigned int GL_NOOP = 0x1505;
		unsigned int GL_XOR = 0x1506;
		unsigned int GL_OR = 0x1507;
		unsigned int GL_NOR = 0x1508;
		unsigned int GL_EQUIV = 0x1509;
		unsigned int GL_INVERT = 0x150A;
		unsigned int GL_OR_REVERSE = 0x150B;
		unsigned int GL_COPY_INVERTED = 0x150C;
		unsigned int GL_OR_INVERTED = 0x150D;
		unsigned int GL_NAND = 0x150E;
		unsigned int GL_SET = 0x150F;
		unsigned int GL_TEXTURE = 0x1702;
		unsigned int GL_COLOR = 0x1800;
		unsigned int GL_DEPTH = 0x1801;
		unsigned int GL_STENCIL = 0x1802;
		unsigned int GL_STENCIL_INDEX = 0x1901;
		unsigned int GL_DEPTH_COMPONENT = 0x1902;
		unsigned int GL_RED = 0x1903;
		unsigned int GL_GREEN = 0x1904;
		unsigned int GL_BLUE = 0x1905;
		unsigned int GL_ALPHA = 0x1906;
		unsigned int GL_RGB = 0x1907;
		unsigned int GL_RGBA = 0x1908;
		unsigned int GL_POINT = 0x1B00;
		unsigned int GL_LINE = 0x1B01;
		unsigned int GL_FILL = 0x1B02;
		unsigned int GL_KEEP = 0x1E00;
		unsigned int GL_REPLACE = 0x1E01;
		unsigned int GL_INCR = 0x1E02;
		unsigned int GL_DECR = 0x1E03;
		unsigned int GL_VENDOR = 0x1F00;
		unsigned int GL_RENDERER = 0x1F01;
		unsigned int GL_VERSION = 0x1F02;
		unsigned int GL_EXTENSIONS = 0x1F03;
		unsigned int GL_NEAREST = 0x2600;
		unsigned int GL_LINEAR = 0x2601;
		unsigned int GL_NEAREST_MIPMAP_NEAREST = 0x2700;
		unsigned int GL_LINEAR_MIPMAP_NEAREST = 0x2701;
		unsigned int GL_NEAREST_MIPMAP_LINEAR = 0x2702;
		unsigned int GL_LINEAR_MIPMAP_LINEAR = 0x2703;
		unsigned int GL_TEXTURE_MAG_FILTER = 0x2800;
		unsigned int GL_TEXTURE_MIN_FILTER = 0x2801;
		unsigned int GL_TEXTURE_WRAP_S = 0x2802;
		unsigned int GL_TEXTURE_WRAP_T = 0x2803;
		unsigned int GL_REPEAT = 0x2901;
		unsigned int GL_COLOR_LOGIC_OP = 0x0BF2;
		unsigned int GL_POLYGON_OFFSET_UNITS = 0x2A00;
		unsigned int GL_POLYGON_OFFSET_POINT = 0x2A01;
		unsigned int GL_POLYGON_OFFSET_LINE = 0x2A02;
		unsigned int GL_POLYGON_OFFSET_FILL = 0x8037;
		unsigned int GL_POLYGON_OFFSET_FACTOR = 0x8038;
		unsigned int GL_TEXTURE_BINDING_1D = 0x8068;
		unsigned int GL_TEXTURE_BINDING_2D = 0x8069;
		unsigned int GL_TEXTURE_INTERNAL_FORMAT = 0x1003;
		unsigned int GL_TEXTURE_RED_SIZE = 0x805C;
		unsigned int GL_TEXTURE_GREEN_SIZE = 0x805D;
		unsigned int GL_TEXTURE_BLUE_SIZE = 0x805E;
		unsigned int GL_TEXTURE_ALPHA_SIZE = 0x805F;
		unsigned int GL_DOUBLE = 0x140A;
		unsigned int GL_PROXY_TEXTURE_1D = 0x8063;
		unsigned int GL_PROXY_TEXTURE_2D = 0x8064;
		unsigned int GL_R3_G3_B2 = 0x2A10;
		unsigned int GL_RGB4 = 0x804F;
		unsigned int GL_RGB5 = 0x8050;
		unsigned int GL_RGB8 = 0x8051;
		unsigned int GL_RGB10 = 0x8052;
		unsigned int GL_RGB12 = 0x8053;
		unsigned int GL_RGB16 = 0x8054;
		unsigned int GL_RGBA2 = 0x8055;
		unsigned int GL_RGBA4 = 0x8056;
		unsigned int GL_RGB5_A1 = 0x8057;
		unsigned int GL_RGBA8 = 0x8058;
		unsigned int GL_RGB10_A2 = 0x8059;
		unsigned int GL_RGBA12 = 0x805A;
		unsigned int GL_RGBA16 = 0x805B;
		unsigned int GL_UNSIGNED_BYTE_3_3_2 = 0x8032;
		unsigned int GL_UNSIGNED_SHORT_4_4_4_4 = 0x8033;
		unsigned int GL_UNSIGNED_SHORT_5_5_5_1 = 0x8034;
		unsigned int GL_UNSIGNED_INT_8_8_8_8 = 0x8035;
		unsigned int GL_UNSIGNED_INT_10_10_10_2 = 0x8036;
		unsigned int GL_TEXTURE_BINDING_3D = 0x806A;
		unsigned int GL_PACK_SKIP_IMAGES = 0x806B;
		unsigned int GL_PACK_IMAGE_HEIGHT = 0x806C;
		unsigned int GL_UNPACK_SKIP_IMAGES = 0x806D;
		unsigned int GL_UNPACK_IMAGE_HEIGHT = 0x806E;
		unsigned int GL_TEXTURE_3D = 0x806F;
		unsigned int GL_PROXY_TEXTURE_3D = 0x8070;
		unsigned int GL_TEXTURE_DEPTH = 0x8071;
		unsigned int GL_TEXTURE_WRAP_R = 0x8072;
		unsigned int GL_MAX_3D_TEXTURE_SIZE = 0x8073;
		unsigned int GL_UNSIGNED_BYTE_2_3_3_REV = 0x8362;
		unsigned int GL_UNSIGNED_SHORT_5_6_5 = 0x8363;
		unsigned int GL_UNSIGNED_SHORT_5_6_5_REV = 0x8364;
		unsigned int GL_UNSIGNED_SHORT_4_4_4_4_REV = 0x8365;
		unsigned int GL_UNSIGNED_SHORT_1_5_5_5_REV = 0x8366;
		unsigned int GL_UNSIGNED_INT_8_8_8_8_REV = 0x8367;
		unsigned int GL_UNSIGNED_INT_2_10_10_10_REV = 0x8368;
		unsigned int GL_BGR = 0x80E0;
		unsigned int GL_BGRA = 0x80E1;
		unsigned int GL_MAX_ELEMENTS_VERTICES = 0x80E8;
		unsigned int GL_MAX_ELEMENTS_INDICES = 0x80E9;
		unsigned int GL_CLAMP_TO_EDGE = 0x812F;
		unsigned int GL_TEXTURE_MIN_LOD = 0x813A;
		unsigned int GL_TEXTURE_MAX_LOD = 0x813B;
		unsigned int GL_TEXTURE_BASE_LEVEL = 0x813C;
		unsigned int GL_TEXTURE_MAX_LEVEL = 0x813D;
		unsigned int GL_SMOOTH_POINT_SIZE_RANGE = 0x0B12;
		unsigned int GL_SMOOTH_POINT_SIZE_GRANULARITY = 0x0B13;
		unsigned int GL_SMOOTH_LINE_WIDTH_RANGE = 0x0B22;
		unsigned int GL_SMOOTH_LINE_WIDTH_GRANULARITY = 0x0B23;
		unsigned int GL_ALIASED_LINE_WIDTH_RANGE = 0x846E;
		unsigned int GL_TEXTURE0 = 0x84C0;
		unsigned int GL_TEXTURE1 = 0x84C1;
		unsigned int GL_TEXTURE2 = 0x84C2;
		unsigned int GL_TEXTURE3 = 0x84C3;
		unsigned int GL_TEXTURE4 = 0x84C4;
		unsigned int GL_TEXTURE5 = 0x84C5;
		unsigned int GL_TEXTURE6 = 0x84C6;
		unsigned int GL_TEXTURE7 = 0x84C7;
		unsigned int GL_TEXTURE8 = 0x84C8;
		unsigned int GL_TEXTURE9 = 0x84C9;
		unsigned int GL_TEXTURE10 = 0x84CA;
		unsigned int GL_TEXTURE11 = 0x84CB;
		unsigned int GL_TEXTURE12 = 0x84CC;
		unsigned int GL_TEXTURE13 = 0x84CD;
		unsigned int GL_TEXTURE14 = 0x84CE;
		unsigned int GL_TEXTURE15 = 0x84CF;
		unsigned int GL_TEXTURE16 = 0x84D0;
		unsigned int GL_TEXTURE17 = 0x84D1;
		unsigned int GL_TEXTURE18 = 0x84D2;
		unsigned int GL_TEXTURE19 = 0x84D3;
		unsigned int GL_TEXTURE20 = 0x84D4;
		unsigned int GL_TEXTURE21 = 0x84D5;
		unsigned int GL_TEXTURE22 = 0x84D6;
		unsigned int GL_TEXTURE23 = 0x84D7;
		unsigned int GL_TEXTURE24 = 0x84D8;
		unsigned int GL_TEXTURE25 = 0x84D9;
		unsigned int GL_TEXTURE26 = 0x84DA;
		unsigned int GL_TEXTURE27 = 0x84DB;
		unsigned int GL_TEXTURE28 = 0x84DC;
		unsigned int GL_TEXTURE29 = 0x84DD;
		unsigned int GL_TEXTURE30 = 0x84DE;
		unsigned int GL_TEXTURE31 = 0x84DF;
		unsigned int GL_ACTIVE_TEXTURE = 0x84E0;
		unsigned int GL_MULTISAMPLE = 0x809D;
		unsigned int GL_SAMPLE_ALPHA_TO_COVERAGE = 0x809E;
		unsigned int GL_SAMPLE_ALPHA_TO_ONE = 0x809F;
		unsigned int GL_SAMPLE_COVERAGE = 0x80A0;
		unsigned int GL_SAMPLE_BUFFERS = 0x80A8;
		unsigned int GL_SAMPLES = 0x80A9;
		unsigned int GL_SAMPLE_COVERAGE_VALUE = 0x80AA;
		unsigned int GL_SAMPLE_COVERAGE_INVERT = 0x80AB;
		unsigned int GL_TEXTURE_CUBE_MAP = 0x8513;
		unsigned int GL_TEXTURE_BINDING_CUBE_MAP = 0x8514;
		unsigned int GL_TEXTURE_CUBE_MAP_POSITIVE_X = 0x8515;
		unsigned int GL_TEXTURE_CUBE_MAP_NEGATIVE_X = 0x8516;
		unsigned int GL_TEXTURE_CUBE_MAP_POSITIVE_Y = 0x8517;
		unsigned int GL_TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x8518;
		unsigned int GL_TEXTURE_CUBE_MAP_POSITIVE_Z = 0x8519;
		unsigned int GL_TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x851A;
		unsigned int GL_PROXY_TEXTURE_CUBE_MAP = 0x851B;
		unsigned int GL_MAX_CUBE_MAP_TEXTURE_SIZE = 0x851C;
		unsigned int GL_COMPRESSED_RGB = 0x84ED;
		unsigned int GL_COMPRESSED_RGBA = 0x84EE;
		unsigned int GL_TEXTURE_COMPRESSION_HINT = 0x84EF;
		unsigned int GL_TEXTURE_COMPRESSED_IMAGE_SIZE = 0x86A0;
		unsigned int GL_TEXTURE_COMPRESSED = 0x86A1;
		unsigned int GL_NUM_COMPRESSED_TEXTURE_FORMATS = 0x86A2;
		unsigned int GL_COMPRESSED_TEXTURE_FORMATS = 0x86A3;
		unsigned int GL_CLAMP_TO_BORDER = 0x812D;
		unsigned int GL_BLEND_DST_RGB = 0x80C8;
		unsigned int GL_BLEND_SRC_RGB = 0x80C9;
		unsigned int GL_BLEND_DST_ALPHA = 0x80CA;
		unsigned int GL_BLEND_SRC_ALPHA = 0x80CB;
		unsigned int GL_POINT_FADE_THRESHOLD_SIZE = 0x8128;
		unsigned int GL_DEPTH_COMPONENT16 = 0x81A5;
		unsigned int GL_DEPTH_COMPONENT24 = 0x81A6;
		unsigned int GL_DEPTH_COMPONENT32 = 0x81A7;
		unsigned int GL_MIRRORED_REPEAT = 0x8370;
		unsigned int GL_MAX_TEXTURE_LOD_BIAS = 0x84FD;
		unsigned int GL_TEXTURE_LOD_BIAS = 0x8501;
		unsigned int GL_INCR_WRAP = 0x8507;
		unsigned int GL_DECR_WRAP = 0x8508;
		unsigned int GL_TEXTURE_DEPTH_SIZE = 0x884A;
		unsigned int GL_TEXTURE_COMPARE_MODE = 0x884C;
		unsigned int GL_TEXTURE_COMPARE_FUNC = 0x884D;
		unsigned int GL_BLEND_COLOR = 0x8005;
		unsigned int GL_BLEND_EQUATION = 0x8009;
		unsigned int GL_CONSTANT_COLOR = 0x8001;
		unsigned int GL_ONE_MINUS_CONSTANT_COLOR = 0x8002;
		unsigned int GL_CONSTANT_ALPHA = 0x8003;
		unsigned int GL_ONE_MINUS_CONSTANT_ALPHA = 0x8004;
		unsigned int GL_FUNC_ADD = 0x8006;
		unsigned int GL_FUNC_REVERSE_SUBTRACT = 0x800B;
		unsigned int GL_FUNC_SUBTRACT = 0x800A;
		unsigned int GL_MIN = 0x8007;
		unsigned int GL_MAX = 0x8008;
		unsigned int GL_BUFFER_SIZE = 0x8764;
		unsigned int GL_BUFFER_USAGE = 0x8765;
		unsigned int GL_QUERY_COUNTER_BITS = 0x8864;
		unsigned int GL_CURRENT_QUERY = 0x8865;
		unsigned int GL_QUERY_RESULT = 0x8866;
		unsigned int GL_QUERY_RESULT_AVAILABLE = 0x8867;
		unsigned int GL_ARRAY_BUFFER = 0x8892;
		unsigned int GL_ELEMENT_ARRAY_BUFFER = 0x8893;
		unsigned int GL_ARRAY_BUFFER_BINDING = 0x8894;
		unsigned int GL_ELEMENT_ARRAY_BUFFER_BINDING = 0x8895;
		unsigned int GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889F;
		unsigned int GL_READ_ONLY = 0x88B8;
		unsigned int GL_WRITE_ONLY = 0x88B9;
		unsigned int GL_READ_WRITE = 0x88BA;
		unsigned int GL_BUFFER_ACCESS = 0x88BB;
		unsigned int GL_BUFFER_MAPPED = 0x88BC;
		unsigned int GL_BUFFER_MAP_POINTER = 0x88BD;
		unsigned int GL_STREAM_DRAW = 0x88E0;
		unsigned int GL_STREAM_READ = 0x88E1;
		unsigned int GL_STREAM_COPY = 0x88E2;
		unsigned int GL_STATIC_DRAW = 0x88E4;
		unsigned int GL_STATIC_READ = 0x88E5;
		unsigned int GL_STATIC_COPY = 0x88E6;
		unsigned int GL_DYNAMIC_DRAW = 0x88E8;
		unsigned int GL_DYNAMIC_READ = 0x88E9;
		unsigned int GL_DYNAMIC_COPY = 0x88EA;
		unsigned int GL_SAMPLES_PASSED = 0x8914;
		unsigned int GL_SRC1_ALPHA = 0x8589;
		unsigned int GL_BLEND_EQUATION_RGB = 0x8009;
		unsigned int GL_VERTEX_ATTRIB_ARRAY_ENABLED = 0x8622;
		unsigned int GL_VERTEX_ATTRIB_ARRAY_SIZE = 0x8623;
		unsigned int GL_VERTEX_ATTRIB_ARRAY_STRIDE = 0x8624;
		unsigned int GL_VERTEX_ATTRIB_ARRAY_TYPE = 0x8625;
		unsigned int GL_CURRENT_VERTEX_ATTRIB = 0x8626;
		unsigned int GL_VERTEX_PROGRAM_POINT_SIZE = 0x8642;
		unsigned int GL_VERTEX_ATTRIB_ARRAY_POINTER = 0x8645;
		unsigned int GL_STENCIL_BACK_FUNC = 0x8800;
		unsigned int GL_STENCIL_BACK_FAIL = 0x8801;
		unsigned int GL_STENCIL_BACK_PASS_DEPTH_FAIL = 0x8802;
		unsigned int GL_STENCIL_BACK_PASS_DEPTH_PASS = 0x8803;
		unsigned int GL_MAX_DRAW_BUFFERS = 0x8824;
		unsigned int GL_DRAW_BUFFER0 = 0x8825;
		unsigned int GL_DRAW_BUFFER1 = 0x8826;
		unsigned int GL_DRAW_BUFFER2 = 0x8827;
		unsigned int GL_DRAW_BUFFER3 = 0x8828;
		unsigned int GL_DRAW_BUFFER4 = 0x8829;
		unsigned int GL_DRAW_BUFFER5 = 0x882A;
		unsigned int GL_DRAW_BUFFER6 = 0x882B;
		unsigned int GL_DRAW_BUFFER7 = 0x882C;
		unsigned int GL_DRAW_BUFFER8 = 0x882D;
		unsigned int GL_DRAW_BUFFER9 = 0x882E;
		unsigned int GL_DRAW_BUFFER10 = 0x882F;
		unsigned int GL_DRAW_BUFFER11 = 0x8830;
		unsigned int GL_DRAW_BUFFER12 = 0x8831;
		unsigned int GL_DRAW_BUFFER13 = 0x8832;
		unsigned int GL_DRAW_BUFFER14 = 0x8833;
		unsigned int GL_DRAW_BUFFER15 = 0x8834;
		unsigned int GL_BLEND_EQUATION_ALPHA = 0x883D;
		unsigned int GL_MAX_VERTEX_ATTRIBS = 0x8869;
		unsigned int GL_VERTEX_ATTRIB_ARRAY_NORMALIZED = 0x886A;
		unsigned int GL_MAX_TEXTURE_IMAGE_UNITS = 0x8872;
		unsigned int GL_FRAGMENT_SHADER = 0x8B30;
		unsigned int GL_VERTEX_SHADER = 0x8B31;
		unsigned int GL_MAX_FRAGMENT_UNIFORM_COMPONENTS = 0x8B49;
		unsigned int GL_MAX_VERTEX_UNIFORM_COMPONENTS = 0x8B4A;
		unsigned int GL_MAX_VARYING_FLOATS = 0x8B4B;
		unsigned int GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS = 0x8B4C;
		unsigned int GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS = 0x8B4D;
		unsigned int GL_SHADER_TYPE = 0x8B4F;
		unsigned int GL_FLOAT_VEC2 = 0x8B50;
		unsigned int GL_FLOAT_VEC3 = 0x8B51;
		unsigned int GL_FLOAT_VEC4 = 0x8B52;
		unsigned int GL_INT_VEC2 = 0x8B53;
		unsigned int GL_INT_VEC3 = 0x8B54;
		unsigned int GL_INT_VEC4 = 0x8B55;
		unsigned int GL_BOOL = 0x8B56;
		unsigned int GL_BOOL_VEC2 = 0x8B57;
		unsigned int GL_BOOL_VEC3 = 0x8B58;
		unsigned int GL_BOOL_VEC4 = 0x8B59;
		unsigned int GL_FLOAT_MAT2 = 0x8B5A;
		unsigned int GL_FLOAT_MAT3 = 0x8B5B;
		unsigned int GL_FLOAT_MAT4 = 0x8B5C;
		unsigned int GL_SAMPLER_1D = 0x8B5D;
		unsigned int GL_SAMPLER_2D = 0x8B5E;
		unsigned int GL_SAMPLER_3D = 0x8B5F;
		unsigned int GL_SAMPLER_CUBE = 0x8B60;
		unsigned int GL_SAMPLER_1D_SHADOW = 0x8B61;
		unsigned int GL_SAMPLER_2D_SHADOW = 0x8B62;
		unsigned int GL_DELETE_STATUS = 0x8B80;
		unsigned int GL_COMPILE_STATUS = 0x8B81;
		unsigned int GL_LINK_STATUS = 0x8B82;
		unsigned int GL_VALIDATE_STATUS = 0x8B83;
		unsigned int GL_INFO_LOG_LENGTH = 0x8B84;
		unsigned int GL_ATTACHED_SHADERS = 0x8B85;
		unsigned int GL_ACTIVE_UNIFORMS = 0x8B86;
		unsigned int GL_ACTIVE_UNIFORM_MAX_LENGTH = 0x8B87;
		unsigned int GL_SHADER_SOURCE_LENGTH = 0x8B88;
		unsigned int GL_ACTIVE_ATTRIBUTES = 0x8B89;
		unsigned int GL_ACTIVE_ATTRIBUTE_MAX_LENGTH = 0x8B8A;
		unsigned int GL_FRAGMENT_SHADER_DERIVATIVE_HINT = 0x8B8B;
		unsigned int GL_SHADING_LANGUAGE_VERSION = 0x8B8C;
		unsigned int GL_CURRENT_PROGRAM = 0x8B8D;
		unsigned int GL_POINT_SPRITE_COORD_ORIGIN = 0x8CA0;
		unsigned int GL_LOWER_LEFT = 0x8CA1;
		unsigned int GL_UPPER_LEFT = 0x8CA2;
		unsigned int GL_STENCIL_BACK_REF = 0x8CA3;
		unsigned int GL_STENCIL_BACK_VALUE_MASK = 0x8CA4;
		unsigned int GL_STENCIL_BACK_WRITEMASK = 0x8CA5;
		unsigned int GL_PIXEL_PACK_BUFFER = 0x88EB;
		unsigned int GL_PIXEL_UNPACK_BUFFER = 0x88EC;
		unsigned int GL_PIXEL_PACK_BUFFER_BINDING = 0x88ED;
		unsigned int GL_PIXEL_UNPACK_BUFFER_BINDING = 0x88EF;
		unsigned int GL_FLOAT_MAT2x3 = 0x8B65;
		unsigned int GL_FLOAT_MAT2x4 = 0x8B66;
		unsigned int GL_FLOAT_MAT3x2 = 0x8B67;
		unsigned int GL_FLOAT_MAT3x4 = 0x8B68;
		unsigned int GL_FLOAT_MAT4x2 = 0x8B69;
		unsigned int GL_FLOAT_MAT4x3 = 0x8B6A;
		unsigned int GL_SRGB = 0x8C40;
		unsigned int GL_SRGB8 = 0x8C41;
		unsigned int GL_SRGB_ALPHA = 0x8C42;
		unsigned int GL_SRGB8_ALPHA8 = 0x8C43;
		unsigned int GL_COMPRESSED_SRGB = 0x8C48;
		unsigned int GL_COMPRESSED_SRGB_ALPHA = 0x8C49;
		unsigned int GL_COMPARE_REF_TO_TEXTURE = 0x884E;
		unsigned int GL_CLIP_DISTANCE0 = 0x3000;
		unsigned int GL_CLIP_DISTANCE1 = 0x3001;
		unsigned int GL_CLIP_DISTANCE2 = 0x3002;
		unsigned int GL_CLIP_DISTANCE3 = 0x3003;
		unsigned int GL_CLIP_DISTANCE4 = 0x3004;
		unsigned int GL_CLIP_DISTANCE5 = 0x3005;
		unsigned int GL_CLIP_DISTANCE6 = 0x3006;
		unsigned int GL_CLIP_DISTANCE7 = 0x3007;
		unsigned int GL_MAX_CLIP_DISTANCES = 0x0D32;
		unsigned int GL_MAJOR_VERSION = 0x821B;
		unsigned int GL_MINOR_VERSION = 0x821C;
		unsigned int GL_NUM_EXTENSIONS = 0x821D;
		unsigned int GL_CONTEXT_FLAGS = 0x821E;
		unsigned int GL_COMPRESSED_RED = 0x8225;
		unsigned int GL_COMPRESSED_RG = 0x8226;
		unsigned int GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT = 0x00000001;
		unsigned int GL_RGBA32F = 0x8814;
		unsigned int GL_RGB32F = 0x8815;
		unsigned int GL_RGBA16F = 0x881A;
		unsigned int GL_RGB16F = 0x881B;
		unsigned int GL_VERTEX_ATTRIB_ARRAY_INTEGER = 0x88FD;
		unsigned int GL_MAX_ARRAY_TEXTURE_LAYERS = 0x88FF;
		unsigned int GL_MIN_PROGRAM_TEXEL_OFFSET = 0x8904;
		unsigned int GL_MAX_PROGRAM_TEXEL_OFFSET = 0x8905;
		unsigned int GL_CLAMP_READ_COLOR = 0x891C;
		unsigned int GL_FIXED_ONLY = 0x891D;
		unsigned int GL_MAX_VARYING_COMPONENTS = 0x8B4B;
		unsigned int GL_TEXTURE_1D_ARRAY = 0x8C18;
		unsigned int GL_PROXY_TEXTURE_1D_ARRAY = 0x8C19;
		unsigned int GL_TEXTURE_2D_ARRAY = 0x8C1A;
		unsigned int GL_PROXY_TEXTURE_2D_ARRAY = 0x8C1B;
		unsigned int GL_TEXTURE_BINDING_1D_ARRAY = 0x8C1C;
		unsigned int GL_TEXTURE_BINDING_2D_ARRAY = 0x8C1D;
		unsigned int GL_R11F_G11F_B10F = 0x8C3A;
		unsigned int GL_UNSIGNED_INT_10F_11F_11F_REV = 0x8C3B;
		unsigned int GL_RGB9_E5 = 0x8C3D;
		unsigned int GL_UNSIGNED_INT_5_9_9_9_REV = 0x8C3E;
		unsigned int GL_TEXTURE_SHARED_SIZE = 0x8C3F;
		unsigned int GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH = 0x8C76;
		unsigned int GL_TRANSFORM_FEEDBACK_BUFFER_MODE = 0x8C7F;
		unsigned int GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS = 0x8C80;
		unsigned int GL_TRANSFORM_FEEDBACK_VARYINGS = 0x8C83;
		unsigned int GL_TRANSFORM_FEEDBACK_BUFFER_START = 0x8C84;
		unsigned int GL_TRANSFORM_FEEDBACK_BUFFER_SIZE = 0x8C85;
		unsigned int GL_PRIMITIVES_GENERATED = 0x8C87;
		unsigned int GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN = 0x8C88;
		unsigned int GL_RASTERIZER_DISCARD = 0x8C89;
		unsigned int GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS = 0x8C8A;
		unsigned int GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS = 0x8C8B;
		unsigned int GL_INTERLEAVED_ATTRIBS = 0x8C8C;
		unsigned int GL_SEPARATE_ATTRIBS = 0x8C8D;
		unsigned int GL_TRANSFORM_FEEDBACK_BUFFER = 0x8C8E;
		unsigned int GL_TRANSFORM_FEEDBACK_BUFFER_BINDING = 0x8C8F;
		unsigned int GL_RGBA32UI = 0x8D70;
		unsigned int GL_RGB32UI = 0x8D71;
		unsigned int GL_RGBA16UI = 0x8D76;
		unsigned int GL_RGB16UI = 0x8D77;
		unsigned int GL_RGBA8UI = 0x8D7C;
		unsigned int GL_RGB8UI = 0x8D7D;
		unsigned int GL_RGBA32I = 0x8D82;
		unsigned int GL_RGB32I = 0x8D83;
		unsigned int GL_RGBA16I = 0x8D88;
		unsigned int GL_RGB16I = 0x8D89;
		unsigned int GL_RGBA8I = 0x8D8E;
		unsigned int GL_RGB8I = 0x8D8F;
		unsigned int GL_RED_INTEGER = 0x8D94;
		unsigned int GL_GREEN_INTEGER = 0x8D95;
		unsigned int GL_BLUE_INTEGER = 0x8D96;
		unsigned int GL_RGB_INTEGER = 0x8D98;
		unsigned int GL_RGBA_INTEGER = 0x8D99;
		unsigned int GL_BGR_INTEGER = 0x8D9A;
		unsigned int GL_BGRA_INTEGER = 0x8D9B;
		unsigned int GL_SAMPLER_1D_ARRAY = 0x8DC0;
		unsigned int GL_SAMPLER_2D_ARRAY = 0x8DC1;
		unsigned int GL_SAMPLER_1D_ARRAY_SHADOW = 0x8DC3;
		unsigned int GL_SAMPLER_2D_ARRAY_SHADOW = 0x8DC4;
		unsigned int GL_SAMPLER_CUBE_SHADOW = 0x8DC5;
		unsigned int GL_UNSIGNED_INT_VEC2 = 0x8DC6;
		unsigned int GL_UNSIGNED_INT_VEC3 = 0x8DC7;
		unsigned int GL_UNSIGNED_INT_VEC4 = 0x8DC8;
		unsigned int GL_INT_SAMPLER_1D = 0x8DC9;
		unsigned int GL_INT_SAMPLER_2D = 0x8DCA;
		unsigned int GL_INT_SAMPLER_3D = 0x8DCB;
		unsigned int GL_INT_SAMPLER_CUBE = 0x8DCC;
		unsigned int GL_INT_SAMPLER_1D_ARRAY = 0x8DCE;
		unsigned int GL_INT_SAMPLER_2D_ARRAY = 0x8DCF;
		unsigned int GL_UNSIGNED_INT_SAMPLER_1D = 0x8DD1;
		unsigned int GL_UNSIGNED_INT_SAMPLER_2D = 0x8DD2;
		unsigned int GL_UNSIGNED_INT_SAMPLER_3D = 0x8DD3;
		unsigned int GL_UNSIGNED_INT_SAMPLER_CUBE = 0x8DD4;
		unsigned int GL_UNSIGNED_INT_SAMPLER_1D_ARRAY = 0x8DD6;
		unsigned int GL_UNSIGNED_INT_SAMPLER_2D_ARRAY = 0x8DD7;
		unsigned int GL_QUERY_WAIT = 0x8E13;
		unsigned int GL_QUERY_NO_WAIT = 0x8E14;
		unsigned int GL_QUERY_BY_REGION_WAIT = 0x8E15;
		unsigned int GL_QUERY_BY_REGION_NO_WAIT = 0x8E16;
		unsigned int GL_BUFFER_ACCESS_FLAGS = 0x911F;
		unsigned int GL_BUFFER_MAP_LENGTH = 0x9120;
		unsigned int GL_BUFFER_MAP_OFFSET = 0x9121;
		unsigned int GL_DEPTH_COMPONENT32F = 0x8CAC;
		unsigned int GL_DEPTH32F_STENCIL8 = 0x8CAD;
		unsigned int GL_FLOAT_32_UNSIGNED_INT_24_8_REV = 0x8DAD;
		unsigned int GL_INVALID_FRAMEBUFFER_OPERATION = 0x0506;
		unsigned int GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING = 0x8210;
		unsigned int GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE = 0x8211;
		unsigned int GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE = 0x8212;
		unsigned int GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE = 0x8213;
		unsigned int GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE = 0x8214;
		unsigned int GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE = 0x8215;
		unsigned int GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE = 0x8216;
		unsigned int GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE = 0x8217;
		unsigned int GL_FRAMEBUFFER_DEFAULT = 0x8218;
		unsigned int GL_FRAMEBUFFER_UNDEFINED = 0x8219;
		unsigned int GL_DEPTH_STENCIL_ATTACHMENT = 0x821A;
		unsigned int GL_MAX_RENDERBUFFER_SIZE = 0x84E8;
		unsigned int GL_DEPTH_STENCIL = 0x84F9;
		unsigned int GL_UNSIGNED_INT_24_8 = 0x84FA;
		unsigned int GL_DEPTH24_STENCIL8 = 0x88F0;
		unsigned int GL_TEXTURE_STENCIL_SIZE = 0x88F1;
		unsigned int GL_TEXTURE_RED_TYPE = 0x8C10;
		unsigned int GL_TEXTURE_GREEN_TYPE = 0x8C11;
		unsigned int GL_TEXTURE_BLUE_TYPE = 0x8C12;
		unsigned int GL_TEXTURE_ALPHA_TYPE = 0x8C13;
		unsigned int GL_TEXTURE_DEPTH_TYPE = 0x8C16;
		unsigned int GL_UNSIGNED_NORMALIZED = 0x8C17;
		unsigned int GL_FRAMEBUFFER_BINDING = 0x8CA6;
		unsigned int GL_DRAW_FRAMEBUFFER_BINDING = 0x8CA6;
		unsigned int GL_RENDERBUFFER_BINDING = 0x8CA7;
		unsigned int GL_READ_FRAMEBUFFER = 0x8CA8;
		unsigned int GL_DRAW_FRAMEBUFFER = 0x8CA9;
		unsigned int GL_READ_FRAMEBUFFER_BINDING = 0x8CAA;
		unsigned int GL_RENDERBUFFER_SAMPLES = 0x8CAB;
		unsigned int GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE = 0x8CD0;
		unsigned int GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME = 0x8CD1;
		unsigned int GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL = 0x8CD2;
		unsigned int GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE = 0x8CD3;
		unsigned int GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER = 0x8CD4;
		unsigned int GL_FRAMEBUFFER_COMPLETE = 0x8CD5;
		unsigned int GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT = 0x8CD6;
		unsigned int GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT = 0x8CD7;
		unsigned int GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER = 0x8CDB;
		unsigned int GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER = 0x8CDC;
		unsigned int GL_FRAMEBUFFER_UNSUPPORTED = 0x8CDD;
		unsigned int GL_MAX_COLOR_ATTACHMENTS = 0x8CDF;
		unsigned int GL_COLOR_ATTACHMENT0 = 0x8CE0;
		unsigned int GL_COLOR_ATTACHMENT1 = 0x8CE1;
		unsigned int GL_COLOR_ATTACHMENT2 = 0x8CE2;
		unsigned int GL_COLOR_ATTACHMENT3 = 0x8CE3;
		unsigned int GL_COLOR_ATTACHMENT4 = 0x8CE4;
		unsigned int GL_COLOR_ATTACHMENT5 = 0x8CE5;
		unsigned int GL_COLOR_ATTACHMENT6 = 0x8CE6;
		unsigned int GL_COLOR_ATTACHMENT7 = 0x8CE7;
		unsigned int GL_COLOR_ATTACHMENT8 = 0x8CE8;
		unsigned int GL_COLOR_ATTACHMENT9 = 0x8CE9;
		unsigned int GL_COLOR_ATTACHMENT10 = 0x8CEA;
		unsigned int GL_COLOR_ATTACHMENT11 = 0x8CEB;
		unsigned int GL_COLOR_ATTACHMENT12 = 0x8CEC;
		unsigned int GL_COLOR_ATTACHMENT13 = 0x8CED;
		unsigned int GL_COLOR_ATTACHMENT14 = 0x8CEE;
		unsigned int GL_COLOR_ATTACHMENT15 = 0x8CEF;
		unsigned int GL_COLOR_ATTACHMENT16 = 0x8CF0;
		unsigned int GL_COLOR_ATTACHMENT17 = 0x8CF1;
		unsigned int GL_COLOR_ATTACHMENT18 = 0x8CF2;
		unsigned int GL_COLOR_ATTACHMENT19 = 0x8CF3;
		unsigned int GL_COLOR_ATTACHMENT20 = 0x8CF4;
		unsigned int GL_COLOR_ATTACHMENT21 = 0x8CF5;
		unsigned int GL_COLOR_ATTACHMENT22 = 0x8CF6;
		unsigned int GL_COLOR_ATTACHMENT23 = 0x8CF7;
		unsigned int GL_COLOR_ATTACHMENT24 = 0x8CF8;
		unsigned int GL_COLOR_ATTACHMENT25 = 0x8CF9;
		unsigned int GL_COLOR_ATTACHMENT26 = 0x8CFA;
		unsigned int GL_COLOR_ATTACHMENT27 = 0x8CFB;
		unsigned int GL_COLOR_ATTACHMENT28 = 0x8CFC;
		unsigned int GL_COLOR_ATTACHMENT29 = 0x8CFD;
		unsigned int GL_COLOR_ATTACHMENT30 = 0x8CFE;
		unsigned int GL_COLOR_ATTACHMENT31 = 0x8CFF;
		unsigned int GL_DEPTH_ATTACHMENT = 0x8D00;
		unsigned int GL_STENCIL_ATTACHMENT = 0x8D20;
		unsigned int GL_FRAMEBUFFER = 0x8D40;
		unsigned int GL_RENDERBUFFER = 0x8D41;
		unsigned int GL_RENDERBUFFER_WIDTH = 0x8D42;
		unsigned int GL_RENDERBUFFER_HEIGHT = 0x8D43;
		unsigned int GL_RENDERBUFFER_INTERNAL_FORMAT = 0x8D44;
		unsigned int GL_STENCIL_INDEX1 = 0x8D46;
		unsigned int GL_STENCIL_INDEX4 = 0x8D47;
		unsigned int GL_STENCIL_INDEX8 = 0x8D48;
		unsigned int GL_STENCIL_INDEX16 = 0x8D49;
		unsigned int GL_RENDERBUFFER_RED_SIZE = 0x8D50;
		unsigned int GL_RENDERBUFFER_GREEN_SIZE = 0x8D51;
		unsigned int GL_RENDERBUFFER_BLUE_SIZE = 0x8D52;
		unsigned int GL_RENDERBUFFER_ALPHA_SIZE = 0x8D53;
		unsigned int GL_RENDERBUFFER_DEPTH_SIZE = 0x8D54;
		unsigned int GL_RENDERBUFFER_STENCIL_SIZE = 0x8D55;
		unsigned int GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE = 0x8D56;
		unsigned int GL_MAX_SAMPLES = 0x8D57;
		unsigned int GL_FRAMEBUFFER_SRGB = 0x8DB9;
		unsigned int GL_HALF_FLOAT = 0x140B;
		unsigned int GL_MAP_READ_BIT = 0x0001;
		unsigned int GL_MAP_WRITE_BIT = 0x0002;
		unsigned int GL_MAP_INVALIDATE_RANGE_BIT = 0x0004;
		unsigned int GL_MAP_INVALIDATE_BUFFER_BIT = 0x0008;
		unsigned int GL_MAP_FLUSH_EXPLICIT_BIT = 0x0010;
		unsigned int GL_MAP_UNSYNCHRONIZED_BIT = 0x0020;
		unsigned int GL_COMPRESSED_RED_RGTC1 = 0x8DBB;
		unsigned int GL_COMPRESSED_SIGNED_RED_RGTC1 = 0x8DBC;
		unsigned int GL_COMPRESSED_RG_RGTC2 = 0x8DBD;
		unsigned int GL_COMPRESSED_SIGNED_RG_RGTC2 = 0x8DBE;
		unsigned int GL_RG = 0x8227;
		unsigned int GL_RG_INTEGER = 0x8228;
		unsigned int GL_R8 = 0x8229;
		unsigned int GL_R16 = 0x822A;
		unsigned int GL_RG8 = 0x822B;
		unsigned int GL_RG16 = 0x822C;
		unsigned int GL_R16F = 0x822D;
		unsigned int GL_R32F = 0x822E;
		unsigned int GL_RG16F = 0x822F;
		unsigned int GL_RG32F = 0x8230;
		unsigned int GL_R8I = 0x8231;
		unsigned int GL_R8UI = 0x8232;
		unsigned int GL_R16I = 0x8233;
		unsigned int GL_R16UI = 0x8234;
		unsigned int GL_R32I = 0x8235;
		unsigned int GL_R32UI = 0x8236;
		unsigned int GL_RG8I = 0x8237;
		unsigned int GL_RG8UI = 0x8238;
		unsigned int GL_RG16I = 0x8239;
		unsigned int GL_RG16UI = 0x823A;
		unsigned int GL_RG32I = 0x823B;
		unsigned int GL_RG32UI = 0x823C;
		unsigned int GL_VERTEX_ARRAY_BINDING = 0x85B5;
		unsigned int GL_SAMPLER_2D_RECT = 0x8B63;
		unsigned int GL_SAMPLER_2D_RECT_SHADOW = 0x8B64;
		unsigned int GL_SAMPLER_BUFFER = 0x8DC2;
		unsigned int GL_INT_SAMPLER_2D_RECT = 0x8DCD;
		unsigned int GL_INT_SAMPLER_BUFFER = 0x8DD0;
		unsigned int GL_UNSIGNED_INT_SAMPLER_2D_RECT = 0x8DD5;
		unsigned int GL_UNSIGNED_INT_SAMPLER_BUFFER = 0x8DD8;
		unsigned int GL_TEXTURE_BUFFER = 0x8C2A;
		unsigned int GL_MAX_TEXTURE_BUFFER_SIZE = 0x8C2B;
		unsigned int GL_TEXTURE_BINDING_BUFFER = 0x8C2C;
		unsigned int GL_TEXTURE_BUFFER_DATA_STORE_BINDING = 0x8C2D;
		unsigned int GL_TEXTURE_RECTANGLE = 0x84F5;
		unsigned int GL_TEXTURE_BINDING_RECTANGLE = 0x84F6;
		unsigned int GL_PROXY_TEXTURE_RECTANGLE = 0x84F7;
		unsigned int GL_MAX_RECTANGLE_TEXTURE_SIZE = 0x84F8;
		unsigned int GL_R8_SNORM = 0x8F94;
		unsigned int GL_RG8_SNORM = 0x8F95;
		unsigned int GL_RGB8_SNORM = 0x8F96;
		unsigned int GL_RGBA8_SNORM = 0x8F97;
		unsigned int GL_R16_SNORM = 0x8F98;
		unsigned int GL_RG16_SNORM = 0x8F99;
		unsigned int GL_RGB16_SNORM = 0x8F9A;
		unsigned int GL_RGBA16_SNORM = 0x8F9B;
		unsigned int GL_SIGNED_NORMALIZED = 0x8F9C;
		unsigned int GL_PRIMITIVE_RESTART = 0x8F9D;
		unsigned int GL_PRIMITIVE_RESTART_INDEX = 0x8F9E;
		unsigned int GL_COPY_READ_BUFFER = 0x8F36;
		unsigned int GL_COPY_WRITE_BUFFER = 0x8F37;
		unsigned int GL_UNIFORM_BUFFER = 0x8A11;
		unsigned int GL_UNIFORM_BUFFER_BINDING = 0x8A28;
		unsigned int GL_UNIFORM_BUFFER_START = 0x8A29;
		unsigned int GL_UNIFORM_BUFFER_SIZE = 0x8A2A;
		unsigned int GL_MAX_VERTEX_UNIFORM_BLOCKS = 0x8A2B;
		unsigned int GL_MAX_GEOMETRY_UNIFORM_BLOCKS = 0x8A2C;
		unsigned int GL_MAX_FRAGMENT_UNIFORM_BLOCKS = 0x8A2D;
		unsigned int GL_MAX_COMBINED_UNIFORM_BLOCKS = 0x8A2E;
		unsigned int GL_MAX_UNIFORM_BUFFER_BINDINGS = 0x8A2F;
		unsigned int GL_MAX_UNIFORM_BLOCK_SIZE = 0x8A30;
		unsigned int GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS = 0x8A31;
		unsigned int GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS = 0x8A32;
		unsigned int GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS = 0x8A33;
		unsigned int GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT = 0x8A34;
		unsigned int GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH = 0x8A35;
		unsigned int GL_ACTIVE_UNIFORM_BLOCKS = 0x8A36;
		unsigned int GL_UNIFORM_TYPE = 0x8A37;
		unsigned int GL_UNIFORM_SIZE = 0x8A38;
		unsigned int GL_UNIFORM_NAME_LENGTH = 0x8A39;
		unsigned int GL_UNIFORM_BLOCK_INDEX = 0x8A3A;
		unsigned int GL_UNIFORM_OFFSET = 0x8A3B;
		unsigned int GL_UNIFORM_ARRAY_STRIDE = 0x8A3C;
		unsigned int GL_UNIFORM_MATRIX_STRIDE = 0x8A3D;
		unsigned int GL_UNIFORM_IS_ROW_MAJOR = 0x8A3E;
		unsigned int GL_UNIFORM_BLOCK_BINDING = 0x8A3F;
		unsigned int GL_UNIFORM_BLOCK_DATA_SIZE = 0x8A40;
		unsigned int GL_UNIFORM_BLOCK_NAME_LENGTH = 0x8A41;
		unsigned int GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS = 0x8A42;
		unsigned int GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES = 0x8A43;
		unsigned int GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER = 0x8A44;
		unsigned int GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER = 0x8A45;
		unsigned int GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER = 0x8A46;
		unsigned int GL_INVALID_INDEX = 0xFFFFFFFF;
		unsigned int GL_CONTEXT_CORE_PROFILE_BIT = 0x00000001;
		unsigned int GL_CONTEXT_COMPATIBILITY_PROFILE_BIT = 0x00000002;
		unsigned int GL_LINES_ADJACENCY = 0x000A;
		unsigned int GL_LINE_STRIP_ADJACENCY = 0x000B;
		unsigned int GL_TRIANGLES_ADJACENCY = 0x000C;
		unsigned int GL_TRIANGLE_STRIP_ADJACENCY = 0x000D;
		unsigned int GL_PROGRAM_POINT_SIZE = 0x8642;
		unsigned int GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS = 0x8C29;
		unsigned int GL_FRAMEBUFFER_ATTACHMENT_LAYERED = 0x8DA7;
		unsigned int GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS = 0x8DA8;
		unsigned int GL_GEOMETRY_SHADER = 0x8DD9;
		unsigned int GL_GEOMETRY_VERTICES_OUT = 0x8916;
		unsigned int GL_GEOMETRY_INPUT_TYPE = 0x8917;
		unsigned int GL_GEOMETRY_OUTPUT_TYPE = 0x8918;
		unsigned int GL_MAX_GEOMETRY_UNIFORM_COMPONENTS = 0x8DDF;
		unsigned int GL_MAX_GEOMETRY_OUTPUT_VERTICES = 0x8DE0;
		unsigned int GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS = 0x8DE1;
		unsigned int GL_MAX_VERTEX_OUTPUT_COMPONENTS = 0x9122;
		unsigned int GL_MAX_GEOMETRY_INPUT_COMPONENTS = 0x9123;
		unsigned int GL_MAX_GEOMETRY_OUTPUT_COMPONENTS = 0x9124;
		unsigned int GL_MAX_FRAGMENT_INPUT_COMPONENTS = 0x9125;
		unsigned int GL_CONTEXT_PROFILE_MASK = 0x9126;
		unsigned int GL_DEPTH_CLAMP = 0x864F;
		unsigned int GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION = 0x8E4C;
		unsigned int GL_FIRST_VERTEX_CONVENTION = 0x8E4D;
		unsigned int GL_LAST_VERTEX_CONVENTION = 0x8E4E;
		unsigned int GL_PROVOKING_VERTEX = 0x8E4F;
		unsigned int GL_TEXTURE_CUBE_MAP_SEAMLESS = 0x884F;
		unsigned int GL_MAX_SERVER_WAIT_TIMEOUT = 0x9111;
		unsigned int GL_OBJECT_TYPE = 0x9112;
		unsigned int GL_SYNC_CONDITION = 0x9113;
		unsigned int GL_SYNC_STATUS = 0x9114;
		unsigned int GL_SYNC_FLAGS = 0x9115;
		unsigned int GL_SYNC_FENCE = 0x9116;
		unsigned int GL_SYNC_GPU_COMMANDS_COMPLETE = 0x9117;
		unsigned int GL_UNSIGNALED = 0x9118;
		unsigned int GL_SIGNALED = 0x9119;
		unsigned int GL_ALREADY_SIGNALED = 0x911A;
		unsigned int GL_TIMEOUT_EXPIRED = 0x911B;
		unsigned int GL_CONDITION_SATISFIED = 0x911C;
		unsigned int GL_WAIT_FAILED = 0x911D;
		unsigned int GL_TIMEOUT_IGNORED = 0xFFFFFFFFFFFFFFFF;
		unsigned int GL_SYNC_FLUSH_COMMANDS_BIT = 0x00000001;
		unsigned int GL_SAMPLE_POSITION = 0x8E50;
		unsigned int GL_SAMPLE_MASK = 0x8E51;
		unsigned int GL_SAMPLE_MASK_VALUE = 0x8E52;
		unsigned int GL_MAX_SAMPLE_MASK_WORDS = 0x8E59;
		unsigned int GL_TEXTURE_2D_MULTISAMPLE = 0x9100;
		unsigned int GL_PROXY_TEXTURE_2D_MULTISAMPLE = 0x9101;
		unsigned int GL_TEXTURE_2D_MULTISAMPLE_ARRAY = 0x9102;
		unsigned int GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY = 0x9103;
		unsigned int GL_TEXTURE_BINDING_2D_MULTISAMPLE = 0x9104;
		unsigned int GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY = 0x9105;
		unsigned int GL_TEXTURE_SAMPLES = 0x9106;
		unsigned int GL_TEXTURE_FIXED_SAMPLE_LOCATIONS = 0x9107;
		unsigned int GL_SAMPLER_2D_MULTISAMPLE = 0x9108;
		unsigned int GL_INT_SAMPLER_2D_MULTISAMPLE = 0x9109;
		unsigned int GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE = 0x910A;
		unsigned int GL_SAMPLER_2D_MULTISAMPLE_ARRAY = 0x910B;
		unsigned int GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY = 0x910C;
		unsigned int GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY = 0x910D;
		unsigned int GL_MAX_COLOR_TEXTURE_SAMPLES = 0x910E;
		unsigned int GL_MAX_DEPTH_TEXTURE_SAMPLES = 0x910F;
		unsigned int GL_MAX_INTEGER_SAMPLES = 0x9110;
		unsigned int GL_VERTEX_ATTRIB_ARRAY_DIVISOR = 0x88FE;
		unsigned int GL_SRC1_COLOR = 0x88F9;
		unsigned int GL_ONE_MINUS_SRC1_COLOR = 0x88FA;
		unsigned int GL_ONE_MINUS_SRC1_ALPHA = 0x88FB;
		unsigned int GL_MAX_DUAL_SOURCE_DRAW_BUFFERS = 0x88FC;
		unsigned int GL_ANY_SAMPLES_PASSED = 0x8C2F;
		unsigned int GL_SAMPLER_BINDING = 0x8919;
		unsigned int GL_RGB10_A2UI = 0x906F;
		unsigned int GL_TEXTURE_SWIZZLE_R = 0x8E42;
		unsigned int GL_TEXTURE_SWIZZLE_G = 0x8E43;
		unsigned int GL_TEXTURE_SWIZZLE_B = 0x8E44;
		unsigned int GL_TEXTURE_SWIZZLE_A = 0x8E45;
		unsigned int GL_TEXTURE_SWIZZLE_RGBA = 0x8E46;
		unsigned int GL_TIME_ELAPSED = 0x88BF;
		unsigned int GL_TIMESTAMP = 0x8E28;
		unsigned int GL_INT_2_10_10_10_REV = 0x8D9F;
		unsigned int GL_SAMPLE_SHADING = 0x8C36;
		unsigned int GL_MIN_SAMPLE_SHADING_VALUE = 0x8C37;
		unsigned int GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET = 0x8E5E;
		unsigned int GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET = 0x8E5F;
		unsigned int GL_TEXTURE_CUBE_MAP_ARRAY = 0x9009;
		unsigned int GL_TEXTURE_BINDING_CUBE_MAP_ARRAY = 0x900A;
		unsigned int GL_PROXY_TEXTURE_CUBE_MAP_ARRAY = 0x900B;
		unsigned int GL_SAMPLER_CUBE_MAP_ARRAY = 0x900C;
		unsigned int GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW = 0x900D;
		unsigned int GL_INT_SAMPLER_CUBE_MAP_ARRAY = 0x900E;
		unsigned int GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY = 0x900F;
		unsigned int GL_DRAW_INDIRECT_BUFFER = 0x8F3F;
		unsigned int GL_DRAW_INDIRECT_BUFFER_BINDING = 0x8F43;
		unsigned int GL_GEOMETRY_SHADER_INVOCATIONS = 0x887F;
		unsigned int GL_MAX_GEOMETRY_SHADER_INVOCATIONS = 0x8E5A;
		unsigned int GL_MIN_FRAGMENT_INTERPOLATION_OFFSET = 0x8E5B;
		unsigned int GL_MAX_FRAGMENT_INTERPOLATION_OFFSET = 0x8E5C;
		unsigned int GL_FRAGMENT_INTERPOLATION_OFFSET_BITS = 0x8E5D;
		unsigned int GL_MAX_VERTEX_STREAMS = 0x8E71;
		unsigned int GL_DOUBLE_VEC2 = 0x8FFC;
		unsigned int GL_DOUBLE_VEC3 = 0x8FFD;
		unsigned int GL_DOUBLE_VEC4 = 0x8FFE;
		unsigned int GL_DOUBLE_MAT2 = 0x8F46;
		unsigned int GL_DOUBLE_MAT3 = 0x8F47;
		unsigned int GL_DOUBLE_MAT4 = 0x8F48;
		unsigned int GL_DOUBLE_MAT2x3 = 0x8F49;
		unsigned int GL_DOUBLE_MAT2x4 = 0x8F4A;
		unsigned int GL_DOUBLE_MAT3x2 = 0x8F4B;
		unsigned int GL_DOUBLE_MAT3x4 = 0x8F4C;
		unsigned int GL_DOUBLE_MAT4x2 = 0x8F4D;
		unsigned int GL_DOUBLE_MAT4x3 = 0x8F4E;
		unsigned int GL_ACTIVE_SUBROUTINES = 0x8DE5;
		unsigned int GL_ACTIVE_SUBROUTINE_UNIFORMS = 0x8DE6;
		unsigned int GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS = 0x8E47;
		unsigned int GL_ACTIVE_SUBROUTINE_MAX_LENGTH = 0x8E48;
		unsigned int GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH = 0x8E49;
		unsigned int GL_MAX_SUBROUTINES = 0x8DE7;
		unsigned int GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS = 0x8DE8;
		unsigned int GL_NUM_COMPATIBLE_SUBROUTINES = 0x8E4A;
		unsigned int GL_COMPATIBLE_SUBROUTINES = 0x8E4B;
		unsigned int GL_PATCHES = 0x000E;
		unsigned int GL_PATCH_VERTICES = 0x8E72;
		unsigned int GL_PATCH_DEFAULT_INNER_LEVEL = 0x8E73;
		unsigned int GL_PATCH_DEFAULT_OUTER_LEVEL = 0x8E74;
		unsigned int GL_TESS_CONTROL_OUTPUT_VERTICES = 0x8E75;
		unsigned int GL_TESS_GEN_MODE = 0x8E76;
		unsigned int GL_TESS_GEN_SPACING = 0x8E77;
		unsigned int GL_TESS_GEN_VERTEX_ORDER = 0x8E78;
		unsigned int GL_TESS_GEN_POINT_MODE = 0x8E79;
		unsigned int GL_ISOLINES = 0x8E7A;
		unsigned int GL_QUADS = 0x0007;
		unsigned int GL_FRACTIONAL_ODD = 0x8E7B;
		unsigned int GL_FRACTIONAL_EVEN = 0x8E7C;
		unsigned int GL_MAX_PATCH_VERTICES = 0x8E7D;
		unsigned int GL_MAX_TESS_GEN_LEVEL = 0x8E7E;
		unsigned int GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS = 0x8E7F;
		unsigned int GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS = 0x8E80;
		unsigned int GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS = 0x8E81;
		unsigned int GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS = 0x8E82;
		unsigned int GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS = 0x8E83;
		unsigned int GL_MAX_TESS_PATCH_COMPONENTS = 0x8E84;
		unsigned int GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS = 0x8E85;
		unsigned int GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS = 0x8E86;
		unsigned int GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS = 0x8E89;
		unsigned int GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS = 0x8E8A;
		unsigned int GL_MAX_TESS_CONTROL_INPUT_COMPONENTS = 0x886C;
		unsigned int GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS = 0x886D;
		unsigned int GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS = 0x8E1E;
		unsigned int GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS = 0x8E1F;
		unsigned int GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER = 0x84F0;
		unsigned int GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER = 0x84F1;
		unsigned int GL_TESS_EVALUATION_SHADER = 0x8E87;
		unsigned int GL_TESS_CONTROL_SHADER = 0x8E88;
		unsigned int GL_TRANSFORM_FEEDBACK = 0x8E22;
		unsigned int GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED = 0x8E23;
		unsigned int GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE = 0x8E24;
		unsigned int GL_TRANSFORM_FEEDBACK_BINDING = 0x8E25;
		unsigned int GL_MAX_TRANSFORM_FEEDBACK_BUFFERS = 0x8E70;
		unsigned int GL_FIXED = 0x140C;
		unsigned int GL_IMPLEMENTATION_COLOR_READ_TYPE = 0x8B9A;
		unsigned int GL_IMPLEMENTATION_COLOR_READ_FORMAT = 0x8B9B;
		unsigned int GL_LOW_FLOAT = 0x8DF0;
		unsigned int GL_MEDIUM_FLOAT = 0x8DF1;
		unsigned int GL_HIGH_FLOAT = 0x8DF2;
		unsigned int GL_LOW_INT = 0x8DF3;
		unsigned int GL_MEDIUM_INT = 0x8DF4;
		unsigned int GL_HIGH_INT = 0x8DF5;
		unsigned int GL_SHADER_COMPILER = 0x8DFA;
		unsigned int GL_SHADER_BINARY_FORMATS = 0x8DF8;
		unsigned int GL_NUM_SHADER_BINARY_FORMATS = 0x8DF9;
		unsigned int GL_MAX_VERTEX_UNIFORM_VECTORS = 0x8DFB;
		unsigned int GL_MAX_VARYING_VECTORS = 0x8DFC;
		unsigned int GL_MAX_FRAGMENT_UNIFORM_VECTORS = 0x8DFD;
		unsigned int GL_RGB565 = 0x8D62;
		unsigned int GL_PROGRAM_BINARY_RETRIEVABLE_HINT = 0x8257;
		unsigned int GL_PROGRAM_BINARY_LENGTH = 0x8741;
		unsigned int GL_NUM_PROGRAM_BINARY_FORMATS = 0x87FE;
		unsigned int GL_PROGRAM_BINARY_FORMATS = 0x87FF;
		unsigned int GL_VERTEX_SHADER_BIT = 0x00000001;
		unsigned int GL_FRAGMENT_SHADER_BIT = 0x00000002;
		unsigned int GL_GEOMETRY_SHADER_BIT = 0x00000004;
		unsigned int GL_TESS_CONTROL_SHADER_BIT = 0x00000008;
		unsigned int GL_TESS_EVALUATION_SHADER_BIT = 0x00000010;
		unsigned int GL_ALL_SHADER_BITS = 0xFFFFFFFF;
		unsigned int GL_PROGRAM_SEPARABLE = 0x8258;
		unsigned int GL_ACTIVE_PROGRAM = 0x8259;
		unsigned int GL_PROGRAM_PIPELINE_BINDING = 0x825A;
		unsigned int GL_MAX_VIEWPORTS = 0x825B;
		unsigned int GL_VIEWPORT_SUBPIXEL_BITS = 0x825C;
		unsigned int GL_VIEWPORT_BOUNDS_RANGE = 0x825D;
		unsigned int GL_LAYER_PROVOKING_VERTEX = 0x825E;
		unsigned int GL_VIEWPORT_INDEX_PROVOKING_VERTEX = 0x825F;
		unsigned int GL_UNDEFINED_VERTEX = 0x8260;
		unsigned int GL_COPY_READ_BUFFER_BINDING = 0x8F36;
		unsigned int GL_COPY_WRITE_BUFFER_BINDING = 0x8F37;
		unsigned int GL_TRANSFORM_FEEDBACK_ACTIVE = 0x8E24;
		unsigned int GL_TRANSFORM_FEEDBACK_PAUSED = 0x8E23;
		unsigned int GL_UNPACK_COMPRESSED_BLOCK_WIDTH = 0x9127;
		unsigned int GL_UNPACK_COMPRESSED_BLOCK_HEIGHT = 0x9128;
		unsigned int GL_UNPACK_COMPRESSED_BLOCK_DEPTH = 0x9129;
		unsigned int GL_UNPACK_COMPRESSED_BLOCK_SIZE = 0x912A;
		unsigned int GL_PACK_COMPRESSED_BLOCK_WIDTH = 0x912B;
		unsigned int GL_PACK_COMPRESSED_BLOCK_HEIGHT = 0x912C;
		unsigned int GL_PACK_COMPRESSED_BLOCK_DEPTH = 0x912D;
		unsigned int GL_PACK_COMPRESSED_BLOCK_SIZE = 0x912E;
		unsigned int GL_NUM_SAMPLE_COUNTS = 0x9380;
		unsigned int GL_MIN_MAP_BUFFER_ALIGNMENT = 0x90BC;
		unsigned int GL_ATOMIC_COUNTER_BUFFER = 0x92C0;
		unsigned int GL_ATOMIC_COUNTER_BUFFER_BINDING = 0x92C1;
		unsigned int GL_ATOMIC_COUNTER_BUFFER_START = 0x92C2;
		unsigned int GL_ATOMIC_COUNTER_BUFFER_SIZE = 0x92C3;
		unsigned int GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE = 0x92C4;
		unsigned int GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS = 0x92C5;
		unsigned int GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES = 0x92C6;
		unsigned int GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER = 0x92C7;
		unsigned int GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER = 0x92C8;
		unsigned int GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER = 0x92C9;
		unsigned int GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER = 0x92CA;
		unsigned int GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER = 0x92CB;
		unsigned int GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS = 0x92CC;
		unsigned int GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS = 0x92CD;
		unsigned int GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS = 0x92CE;
		unsigned int GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS = 0x92CF;
		unsigned int GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS = 0x92D0;
		unsigned int GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS = 0x92D1;
		unsigned int GL_MAX_VERTEX_ATOMIC_COUNTERS = 0x92D2;
		unsigned int GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS = 0x92D3;
		unsigned int GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS = 0x92D4;
		unsigned int GL_MAX_GEOMETRY_ATOMIC_COUNTERS = 0x92D5;
		unsigned int GL_MAX_FRAGMENT_ATOMIC_COUNTERS = 0x92D6;
		unsigned int GL_MAX_COMBINED_ATOMIC_COUNTERS = 0x92D7;
		unsigned int GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE = 0x92D8;
		unsigned int GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS = 0x92DC;
		unsigned int GL_ACTIVE_ATOMIC_COUNTER_BUFFERS = 0x92D9;
		unsigned int GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX = 0x92DA;
		unsigned int GL_UNSIGNED_INT_ATOMIC_COUNTER = 0x92DB;
		unsigned int GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT = 0x00000001;
		unsigned int GL_ELEMENT_ARRAY_BARRIER_BIT = 0x00000002;
		unsigned int GL_UNIFORM_BARRIER_BIT = 0x00000004;
		unsigned int GL_TEXTURE_FETCH_BARRIER_BIT = 0x00000008;
		unsigned int GL_SHADER_IMAGE_ACCESS_BARRIER_BIT = 0x00000020;
		unsigned int GL_COMMAND_BARRIER_BIT = 0x00000040;
		unsigned int GL_PIXEL_BUFFER_BARRIER_BIT = 0x00000080;
		unsigned int GL_TEXTURE_UPDATE_BARRIER_BIT = 0x00000100;
		unsigned int GL_BUFFER_UPDATE_BARRIER_BIT = 0x00000200;
		unsigned int GL_FRAMEBUFFER_BARRIER_BIT = 0x00000400;
		unsigned int GL_TRANSFORM_FEEDBACK_BARRIER_BIT = 0x00000800;
		unsigned int GL_ATOMIC_COUNTER_BARRIER_BIT = 0x00001000;
		unsigned int GL_ALL_BARRIER_BITS = 0xFFFFFFFF;
		unsigned int GL_MAX_IMAGE_UNITS = 0x8F38;
		unsigned int GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS = 0x8F39;
		unsigned int GL_IMAGE_BINDING_NAME = 0x8F3A;
		unsigned int GL_IMAGE_BINDING_LEVEL = 0x8F3B;
		unsigned int GL_IMAGE_BINDING_LAYERED = 0x8F3C;
		unsigned int GL_IMAGE_BINDING_LAYER = 0x8F3D;
		unsigned int GL_IMAGE_BINDING_ACCESS = 0x8F3E;
		unsigned int GL_IMAGE_1D = 0x904C;
		unsigned int GL_IMAGE_2D = 0x904D;
		unsigned int GL_IMAGE_3D = 0x904E;
		unsigned int GL_IMAGE_2D_RECT = 0x904F;
		unsigned int GL_IMAGE_CUBE = 0x9050;
		unsigned int GL_IMAGE_BUFFER = 0x9051;
		unsigned int GL_IMAGE_1D_ARRAY = 0x9052;
		unsigned int GL_IMAGE_2D_ARRAY = 0x9053;
		unsigned int GL_IMAGE_CUBE_MAP_ARRAY = 0x9054;
		unsigned int GL_IMAGE_2D_MULTISAMPLE = 0x9055;
		unsigned int GL_IMAGE_2D_MULTISAMPLE_ARRAY = 0x9056;
		unsigned int GL_INT_IMAGE_1D = 0x9057;
		unsigned int GL_INT_IMAGE_2D = 0x9058;
		unsigned int GL_INT_IMAGE_3D = 0x9059;
		unsigned int GL_INT_IMAGE_2D_RECT = 0x905A;
		unsigned int GL_INT_IMAGE_CUBE = 0x905B;
		unsigned int GL_INT_IMAGE_BUFFER = 0x905C;
		unsigned int GL_INT_IMAGE_1D_ARRAY = 0x905D;
		unsigned int GL_INT_IMAGE_2D_ARRAY = 0x905E;
		unsigned int GL_INT_IMAGE_CUBE_MAP_ARRAY = 0x905F;
		unsigned int GL_INT_IMAGE_2D_MULTISAMPLE = 0x9060;
		unsigned int GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY = 0x9061;
		unsigned int GL_UNSIGNED_INT_IMAGE_1D = 0x9062;
		unsigned int GL_UNSIGNED_INT_IMAGE_2D = 0x9063;
		unsigned int GL_UNSIGNED_INT_IMAGE_3D = 0x9064;
		unsigned int GL_UNSIGNED_INT_IMAGE_2D_RECT = 0x9065;
		unsigned int GL_UNSIGNED_INT_IMAGE_CUBE = 0x9066;
		unsigned int GL_UNSIGNED_INT_IMAGE_BUFFER = 0x9067;
		unsigned int GL_UNSIGNED_INT_IMAGE_1D_ARRAY = 0x9068;
		unsigned int GL_UNSIGNED_INT_IMAGE_2D_ARRAY = 0x9069;
		unsigned int GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY = 0x906A;
		unsigned int GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE = 0x906B;
		unsigned int GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY = 0x906C;
		unsigned int GL_MAX_IMAGE_SAMPLES = 0x906D;
		unsigned int GL_IMAGE_BINDING_FORMAT = 0x906E;
		unsigned int GL_IMAGE_FORMAT_COMPATIBILITY_TYPE = 0x90C7;
		unsigned int GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE = 0x90C8;
		unsigned int GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS = 0x90C9;
		unsigned int GL_MAX_VERTEX_IMAGE_UNIFORMS = 0x90CA;
		unsigned int GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS = 0x90CB;
		unsigned int GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS = 0x90CC;
		unsigned int GL_MAX_GEOMETRY_IMAGE_UNIFORMS = 0x90CD;
		unsigned int GL_MAX_FRAGMENT_IMAGE_UNIFORMS = 0x90CE;
		unsigned int GL_MAX_COMBINED_IMAGE_UNIFORMS = 0x90CF;
		unsigned int GL_COMPRESSED_RGBA_BPTC_UNORM = 0x8E8C;
		unsigned int GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM = 0x8E8D;
		unsigned int GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT = 0x8E8E;
		unsigned int GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT = 0x8E8F;
		unsigned int GL_TEXTURE_IMMUTABLE_FORMAT = 0x912F;
		unsigned int GL_NUM_SHADING_LANGUAGE_VERSIONS = 0x82E9;
		unsigned int GL_VERTEX_ATTRIB_ARRAY_LONG = 0x874E;
		unsigned int GL_COMPRESSED_RGB8_ETC2 = 0x9274;
		unsigned int GL_COMPRESSED_SRGB8_ETC2 = 0x9275;
		unsigned int GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 = 0x9276;
		unsigned int GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 = 0x9277;
		unsigned int GL_COMPRESSED_RGBA8_ETC2_EAC = 0x9278;
		unsigned int GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC = 0x9279;
		unsigned int GL_COMPRESSED_R11_EAC = 0x9270;
		unsigned int GL_COMPRESSED_SIGNED_R11_EAC = 0x9271;
		unsigned int GL_COMPRESSED_RG11_EAC = 0x9272;
		unsigned int GL_COMPRESSED_SIGNED_RG11_EAC = 0x9273;
		unsigned int GL_PRIMITIVE_RESTART_FIXED_INDEX = 0x8D69;
		unsigned int GL_ANY_SAMPLES_PASSED_CONSERVATIVE = 0x8D6A;
		unsigned int GL_MAX_ELEMENT_INDEX = 0x8D6B;
		unsigned int GL_COMPUTE_SHADER = 0x91B9;
		unsigned int GL_MAX_COMPUTE_UNIFORM_BLOCKS = 0x91BB;
		unsigned int GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS = 0x91BC;
		unsigned int GL_MAX_COMPUTE_IMAGE_UNIFORMS = 0x91BD;
		unsigned int GL_MAX_COMPUTE_SHARED_MEMORY_SIZE = 0x8262;
		unsigned int GL_MAX_COMPUTE_UNIFORM_COMPONENTS = 0x8263;
		unsigned int GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS = 0x8264;
		unsigned int GL_MAX_COMPUTE_ATOMIC_COUNTERS = 0x8265;
		unsigned int GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS = 0x8266;
		unsigned int GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS = 0x90EB;
		unsigned int GL_MAX_COMPUTE_WORK_GROUP_COUNT = 0x91BE;
		unsigned int GL_MAX_COMPUTE_WORK_GROUP_SIZE = 0x91BF;
		unsigned int GL_COMPUTE_WORK_GROUP_SIZE = 0x8267;
		unsigned int GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER = 0x90EC;
		unsigned int GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER = 0x90ED;
		unsigned int GL_DISPATCH_INDIRECT_BUFFER = 0x90EE;
		unsigned int GL_DISPATCH_INDIRECT_BUFFER_BINDING = 0x90EF;
		unsigned int GL_COMPUTE_SHADER_BIT = 0x00000020;
		unsigned int GL_DEBUG_OUTPUT_SYNCHRONOUS = 0x8242;
		unsigned int GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH = 0x8243;
		unsigned int GL_DEBUG_CALLBACK_FUNCTION = 0x8244;
		unsigned int GL_DEBUG_CALLBACK_USER_PARAM = 0x8245;
		unsigned int GL_DEBUG_SOURCE_API = 0x8246;
		unsigned int GL_DEBUG_SOURCE_WINDOW_SYSTEM = 0x8247;
		unsigned int GL_DEBUG_SOURCE_SHADER_COMPILER = 0x8248;
		unsigned int GL_DEBUG_SOURCE_THIRD_PARTY = 0x8249;
		unsigned int GL_DEBUG_SOURCE_APPLICATION = 0x824A;
		unsigned int GL_DEBUG_SOURCE_OTHER = 0x824B;
		unsigned int GL_DEBUG_TYPE_ERROR = 0x824C;
		unsigned int GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR = 0x824D;
		unsigned int GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR = 0x824E;
		unsigned int GL_DEBUG_TYPE_PORTABILITY = 0x824F;
		unsigned int GL_DEBUG_TYPE_PERFORMANCE = 0x8250;
		unsigned int GL_DEBUG_TYPE_OTHER = 0x8251;
		unsigned int GL_MAX_DEBUG_MESSAGE_LENGTH = 0x9143;
		unsigned int GL_MAX_DEBUG_LOGGED_MESSAGES = 0x9144;
		unsigned int GL_DEBUG_LOGGED_MESSAGES = 0x9145;
		unsigned int GL_DEBUG_SEVERITY_HIGH = 0x9146;
		unsigned int GL_DEBUG_SEVERITY_MEDIUM = 0x9147;
		unsigned int GL_DEBUG_SEVERITY_LOW = 0x9148;
		unsigned int GL_DEBUG_TYPE_MARKER = 0x8268;
		unsigned int GL_DEBUG_TYPE_PUSH_GROUP = 0x8269;
		unsigned int GL_DEBUG_TYPE_POP_GROUP = 0x826A;
		unsigned int GL_DEBUG_SEVERITY_NOTIFICATION = 0x826B;
		unsigned int GL_MAX_DEBUG_GROUP_STACK_DEPTH = 0x826C;
		unsigned int GL_DEBUG_GROUP_STACK_DEPTH = 0x826D;
		unsigned int GL_BUFFER = 0x82E0;
		unsigned int GL_SHADER = 0x82E1;
		unsigned int GL_PROGRAM = 0x82E2;
		unsigned int GL_VERTEX_ARRAY = 0x8074;
		unsigned int GL_QUERY = 0x82E3;
		unsigned int GL_PROGRAM_PIPELINE = 0x82E4;
		unsigned int GL_SAMPLER = 0x82E6;
		unsigned int GL_MAX_LABEL_LENGTH = 0x82E8;
		unsigned int GL_DEBUG_OUTPUT = 0x92E0;
		unsigned int GL_CONTEXT_FLAG_DEBUG_BIT = 0x00000002;
		unsigned int GL_MAX_UNIFORM_LOCATIONS = 0x826E;
		unsigned int GL_FRAMEBUFFER_DEFAULT_WIDTH = 0x9310;
		unsigned int GL_FRAMEBUFFER_DEFAULT_HEIGHT = 0x9311;
		unsigned int GL_FRAMEBUFFER_DEFAULT_LAYERS = 0x9312;
		unsigned int GL_FRAMEBUFFER_DEFAULT_SAMPLES = 0x9313;
		unsigned int GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS = 0x9314;
		unsigned int GL_MAX_FRAMEBUFFER_WIDTH = 0x9315;
		unsigned int GL_MAX_FRAMEBUFFER_HEIGHT = 0x9316;
		unsigned int GL_MAX_FRAMEBUFFER_LAYERS = 0x9317;
		unsigned int GL_MAX_FRAMEBUFFER_SAMPLES = 0x9318;
		unsigned int GL_INTERNALFORMAT_SUPPORTED = 0x826F;
		unsigned int GL_INTERNALFORMAT_PREFERRED = 0x8270;
		unsigned int GL_INTERNALFORMAT_RED_SIZE = 0x8271;
		unsigned int GL_INTERNALFORMAT_GREEN_SIZE = 0x8272;
		unsigned int GL_INTERNALFORMAT_BLUE_SIZE = 0x8273;
		unsigned int GL_INTERNALFORMAT_ALPHA_SIZE = 0x8274;
		unsigned int GL_INTERNALFORMAT_DEPTH_SIZE = 0x8275;
		unsigned int GL_INTERNALFORMAT_STENCIL_SIZE = 0x8276;
		unsigned int GL_INTERNALFORMAT_SHARED_SIZE = 0x8277;
		unsigned int GL_INTERNALFORMAT_RED_TYPE = 0x8278;
		unsigned int GL_INTERNALFORMAT_GREEN_TYPE = 0x8279;
		unsigned int GL_INTERNALFORMAT_BLUE_TYPE = 0x827A;
		unsigned int GL_INTERNALFORMAT_ALPHA_TYPE = 0x827B;
		unsigned int GL_INTERNALFORMAT_DEPTH_TYPE = 0x827C;
		unsigned int GL_INTERNALFORMAT_STENCIL_TYPE = 0x827D;
		unsigned int GL_MAX_WIDTH = 0x827E;
		unsigned int GL_MAX_HEIGHT = 0x827F;
		unsigned int GL_MAX_DEPTH = 0x8280;
		unsigned int GL_MAX_LAYERS = 0x8281;
		unsigned int GL_MAX_COMBINED_DIMENSIONS = 0x8282;
		unsigned int GL_COLOR_COMPONENTS = 0x8283;
		unsigned int GL_DEPTH_COMPONENTS = 0x8284;
		unsigned int GL_STENCIL_COMPONENTS = 0x8285;
		unsigned int GL_COLOR_RENDERABLE = 0x8286;
		unsigned int GL_DEPTH_RENDERABLE = 0x8287;
		unsigned int GL_STENCIL_RENDERABLE = 0x8288;
		unsigned int GL_FRAMEBUFFER_RENDERABLE = 0x8289;
		unsigned int GL_FRAMEBUFFER_RENDERABLE_LAYERED = 0x828A;
		unsigned int GL_FRAMEBUFFER_BLEND = 0x828B;
		unsigned int GL_READ_PIXELS = 0x828C;
		unsigned int GL_READ_PIXELS_FORMAT = 0x828D;
		unsigned int GL_READ_PIXELS_TYPE = 0x828E;
		unsigned int GL_TEXTURE_IMAGE_FORMAT = 0x828F;
		unsigned int GL_TEXTURE_IMAGE_TYPE = 0x8290;
		unsigned int GL_GET_TEXTURE_IMAGE_FORMAT = 0x8291;
		unsigned int GL_GET_TEXTURE_IMAGE_TYPE = 0x8292;
		unsigned int GL_MIPMAP = 0x8293;
		unsigned int GL_MANUAL_GENERATE_MIPMAP = 0x8294;
		unsigned int GL_AUTO_GENERATE_MIPMAP = 0x8295;
		unsigned int GL_COLOR_ENCODING = 0x8296;
		unsigned int GL_SRGB_READ = 0x8297;
		unsigned int GL_SRGB_WRITE = 0x8298;
		unsigned int GL_FILTER = 0x829A;
		unsigned int GL_VERTEX_TEXTURE = 0x829B;
		unsigned int GL_TESS_CONTROL_TEXTURE = 0x829C;
		unsigned int GL_TESS_EVALUATION_TEXTURE = 0x829D;
		unsigned int GL_GEOMETRY_TEXTURE = 0x829E;
		unsigned int GL_FRAGMENT_TEXTURE = 0x829F;
		unsigned int GL_COMPUTE_TEXTURE = 0x82A0;
		unsigned int GL_TEXTURE_SHADOW = 0x82A1;
		unsigned int GL_TEXTURE_GATHER = 0x82A2;
		unsigned int GL_TEXTURE_GATHER_SHADOW = 0x82A3;
		unsigned int GL_SHADER_IMAGE_LOAD = 0x82A4;
		unsigned int GL_SHADER_IMAGE_STORE = 0x82A5;
		unsigned int GL_SHADER_IMAGE_ATOMIC = 0x82A6;
		unsigned int GL_IMAGE_TEXEL_SIZE = 0x82A7;
		unsigned int GL_IMAGE_COMPATIBILITY_CLASS = 0x82A8;
		unsigned int GL_IMAGE_PIXEL_FORMAT = 0x82A9;
		unsigned int GL_IMAGE_PIXEL_TYPE = 0x82AA;
		unsigned int GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST = 0x82AC;
		unsigned int GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST = 0x82AD;
		unsigned int GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE = 0x82AE;
		unsigned int GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE = 0x82AF;
		unsigned int GL_TEXTURE_COMPRESSED_BLOCK_WIDTH = 0x82B1;
		unsigned int GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT = 0x82B2;
		unsigned int GL_TEXTURE_COMPRESSED_BLOCK_SIZE = 0x82B3;
		unsigned int GL_CLEAR_BUFFER = 0x82B4;
		unsigned int GL_TEXTURE_VIEW = 0x82B5;
		unsigned int GL_VIEW_COMPATIBILITY_CLASS = 0x82B6;
		unsigned int GL_FULL_SUPPORT = 0x82B7;
		unsigned int GL_CAVEAT_SUPPORT = 0x82B8;
		unsigned int GL_IMAGE_CLASS_4_X_32 = 0x82B9;
		unsigned int GL_IMAGE_CLASS_2_X_32 = 0x82BA;
		unsigned int GL_IMAGE_CLASS_1_X_32 = 0x82BB;
		unsigned int GL_IMAGE_CLASS_4_X_16 = 0x82BC;
		unsigned int GL_IMAGE_CLASS_2_X_16 = 0x82BD;
		unsigned int GL_IMAGE_CLASS_1_X_16 = 0x82BE;
		unsigned int GL_IMAGE_CLASS_4_X_8 = 0x82BF;
		unsigned int GL_IMAGE_CLASS_2_X_8 = 0x82C0;
		unsigned int GL_IMAGE_CLASS_1_X_8 = 0x82C1;
		unsigned int GL_IMAGE_CLASS_11_11_10 = 0x82C2;
		unsigned int GL_IMAGE_CLASS_10_10_10_2 = 0x82C3;
		unsigned int GL_VIEW_CLASS_128_BITS = 0x82C4;
		unsigned int GL_VIEW_CLASS_96_BITS = 0x82C5;
		unsigned int GL_VIEW_CLASS_64_BITS = 0x82C6;
		unsigned int GL_VIEW_CLASS_48_BITS = 0x82C7;
		unsigned int GL_VIEW_CLASS_32_BITS = 0x82C8;
		unsigned int GL_VIEW_CLASS_24_BITS = 0x82C9;
		unsigned int GL_VIEW_CLASS_16_BITS = 0x82CA;
		unsigned int GL_VIEW_CLASS_8_BITS = 0x82CB;
		unsigned int GL_VIEW_CLASS_S3TC_DXT1_RGB = 0x82CC;
		unsigned int GL_VIEW_CLASS_S3TC_DXT1_RGBA = 0x82CD;
		unsigned int GL_VIEW_CLASS_S3TC_DXT3_RGBA = 0x82CE;
		unsigned int GL_VIEW_CLASS_S3TC_DXT5_RGBA = 0x82CF;
		unsigned int GL_VIEW_CLASS_RGTC1_RED = 0x82D0;
		unsigned int GL_VIEW_CLASS_RGTC2_RG = 0x82D1;
		unsigned int GL_VIEW_CLASS_BPTC_UNORM = 0x82D2;
		unsigned int GL_VIEW_CLASS_BPTC_FLOAT = 0x82D3;
		unsigned int GL_UNIFORM = 0x92E1;
		unsigned int GL_UNIFORM_BLOCK = 0x92E2;
		unsigned int GL_PROGRAM_INPUT = 0x92E3;
		unsigned int GL_PROGRAM_OUTPUT = 0x92E4;
		unsigned int GL_BUFFER_VARIABLE = 0x92E5;
		unsigned int GL_SHADER_STORAGE_BLOCK = 0x92E6;
		unsigned int GL_VERTEX_SUBROUTINE = 0x92E8;
		unsigned int GL_TESS_CONTROL_SUBROUTINE = 0x92E9;
		unsigned int GL_TESS_EVALUATION_SUBROUTINE = 0x92EA;
		unsigned int GL_GEOMETRY_SUBROUTINE = 0x92EB;
		unsigned int GL_FRAGMENT_SUBROUTINE = 0x92EC;
		unsigned int GL_COMPUTE_SUBROUTINE = 0x92ED;
		unsigned int GL_VERTEX_SUBROUTINE_UNIFORM = 0x92EE;
		unsigned int GL_TESS_CONTROL_SUBROUTINE_UNIFORM = 0x92EF;
		unsigned int GL_TESS_EVALUATION_SUBROUTINE_UNIFORM = 0x92F0;
		unsigned int GL_GEOMETRY_SUBROUTINE_UNIFORM = 0x92F1;
		unsigned int GL_FRAGMENT_SUBROUTINE_UNIFORM = 0x92F2;
		unsigned int GL_COMPUTE_SUBROUTINE_UNIFORM = 0x92F3;
		unsigned int GL_TRANSFORM_FEEDBACK_VARYING = 0x92F4;
		unsigned int GL_ACTIVE_RESOURCES = 0x92F5;
		unsigned int GL_MAX_NAME_LENGTH = 0x92F6;
		unsigned int GL_MAX_NUM_ACTIVE_VARIABLES = 0x92F7;
		unsigned int GL_MAX_NUM_COMPATIBLE_SUBROUTINES = 0x92F8;
		unsigned int GL_NAME_LENGTH = 0x92F9;
		unsigned int GL_TYPE = 0x92FA;
		unsigned int GL_ARRAY_SIZE = 0x92FB;
		unsigned int GL_OFFSET = 0x92FC;
		unsigned int GL_BLOCK_INDEX = 0x92FD;
		unsigned int GL_ARRAY_STRIDE = 0x92FE;
		unsigned int GL_MATRIX_STRIDE = 0x92FF;
		unsigned int GL_IS_ROW_MAJOR = 0x9300;
		unsigned int GL_ATOMIC_COUNTER_BUFFER_INDEX = 0x9301;
		unsigned int GL_BUFFER_BINDING = 0x9302;
		unsigned int GL_BUFFER_DATA_SIZE = 0x9303;
		unsigned int GL_NUM_ACTIVE_VARIABLES = 0x9304;
		unsigned int GL_ACTIVE_VARIABLES = 0x9305;
		unsigned int GL_REFERENCED_BY_VERTEX_SHADER = 0x9306;
		unsigned int GL_REFERENCED_BY_TESS_CONTROL_SHADER = 0x9307;
		unsigned int GL_REFERENCED_BY_TESS_EVALUATION_SHADER = 0x9308;
		unsigned int GL_REFERENCED_BY_GEOMETRY_SHADER = 0x9309;
		unsigned int GL_REFERENCED_BY_FRAGMENT_SHADER = 0x930A;
		unsigned int GL_REFERENCED_BY_COMPUTE_SHADER = 0x930B;
		unsigned int GL_TOP_LEVEL_ARRAY_SIZE = 0x930C;
		unsigned int GL_TOP_LEVEL_ARRAY_STRIDE = 0x930D;
		unsigned int GL_LOCATION = 0x930E;
		unsigned int GL_LOCATION_INDEX = 0x930F;
		unsigned int GL_IS_PER_PATCH = 0x92E7;
		unsigned int GL_SHADER_STORAGE_BUFFER = 0x90D2;
		unsigned int GL_SHADER_STORAGE_BUFFER_BINDING = 0x90D3;
		unsigned int GL_SHADER_STORAGE_BUFFER_START = 0x90D4;
		unsigned int GL_SHADER_STORAGE_BUFFER_SIZE = 0x90D5;
		unsigned int GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS = 0x90D6;
		unsigned int GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS = 0x90D7;
		unsigned int GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS = 0x90D8;
		unsigned int GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS = 0x90D9;
		unsigned int GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS = 0x90DA;
		unsigned int GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS = 0x90DB;
		unsigned int GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS = 0x90DC;
		unsigned int GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS = 0x90DD;
		unsigned int GL_MAX_SHADER_STORAGE_BLOCK_SIZE = 0x90DE;
		unsigned int GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT = 0x90DF;
		unsigned int GL_SHADER_STORAGE_BARRIER_BIT = 0x00002000;
		unsigned int GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES = 0x8F39;
		unsigned int GL_DEPTH_STENCIL_TEXTURE_MODE = 0x90EA;
		unsigned int GL_TEXTURE_BUFFER_OFFSET = 0x919D;
		unsigned int GL_TEXTURE_BUFFER_SIZE = 0x919E;
		unsigned int GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT = 0x919F;
		unsigned int GL_TEXTURE_VIEW_MIN_LEVEL = 0x82DB;
		unsigned int GL_TEXTURE_VIEW_NUM_LEVELS = 0x82DC;
		unsigned int GL_TEXTURE_VIEW_MIN_LAYER = 0x82DD;
		unsigned int GL_TEXTURE_VIEW_NUM_LAYERS = 0x82DE;
		unsigned int GL_TEXTURE_IMMUTABLE_LEVELS = 0x82DF;
		unsigned int GL_VERTEX_ATTRIB_BINDING = 0x82D4;
		unsigned int GL_VERTEX_ATTRIB_RELATIVE_OFFSET = 0x82D5;
		unsigned int GL_VERTEX_BINDING_DIVISOR = 0x82D6;
		unsigned int GL_VERTEX_BINDING_OFFSET = 0x82D7;
		unsigned int GL_VERTEX_BINDING_STRIDE = 0x82D8;
		unsigned int GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET = 0x82D9;
		unsigned int GL_MAX_VERTEX_ATTRIB_BINDINGS = 0x82DA;
		unsigned int GL_VERTEX_BINDING_BUFFER = 0x8F4F;
		unsigned int GL_DISPLAY_LIST = 0x82E7;
		unsigned int GL_STACK_UNDERFLOW = 0x0504;
		unsigned int GL_STACK_OVERFLOW = 0x0503;
		unsigned int GL_MAX_VERTEX_ATTRIB_STRIDE = 0x82E5;
		unsigned int GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED = 0x8221;
		unsigned int GL_TEXTURE_BUFFER_BINDING = 0x8C2A;
		unsigned int GL_MAP_PERSISTENT_BIT = 0x0040;
		unsigned int GL_MAP_COHERENT_BIT = 0x0080;
		unsigned int GL_DYNAMIC_STORAGE_BIT = 0x0100;
		unsigned int GL_CLIENT_STORAGE_BIT = 0x0200;
		unsigned int GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT = 0x00004000;
		unsigned int GL_BUFFER_IMMUTABLE_STORAGE = 0x821F;
		unsigned int GL_BUFFER_STORAGE_FLAGS = 0x8220;
		unsigned int GL_CLEAR_TEXTURE = 0x9365;
		unsigned int GL_LOCATION_COMPONENT = 0x934A;
		unsigned int GL_TRANSFORM_FEEDBACK_BUFFER_INDEX = 0x934B;
		unsigned int GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE = 0x934C;
		unsigned int GL_QUERY_BUFFER = 0x9192;
		unsigned int GL_QUERY_BUFFER_BARRIER_BIT = 0x00008000;
		unsigned int GL_QUERY_BUFFER_BINDING = 0x9193;
		unsigned int GL_QUERY_RESULT_NO_WAIT = 0x9194;
		unsigned int GL_MIRROR_CLAMP_TO_EDGE = 0x8743;
		unsigned int GL_CONTEXT_LOST = 0x0507;
		unsigned int GL_NEGATIVE_ONE_TO_ONE = 0x935E;
		unsigned int GL_ZERO_TO_ONE = 0x935F;
		unsigned int GL_CLIP_ORIGIN = 0x935C;
		unsigned int GL_CLIP_DEPTH_MODE = 0x935D;
		unsigned int GL_QUERY_WAIT_INVERTED = 0x8E17;
		unsigned int GL_QUERY_NO_WAIT_INVERTED = 0x8E18;
		unsigned int GL_QUERY_BY_REGION_WAIT_INVERTED = 0x8E19;
		unsigned int GL_QUERY_BY_REGION_NO_WAIT_INVERTED = 0x8E1A;
		unsigned int GL_MAX_CULL_DISTANCES = 0x82F9;
		unsigned int GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES = 0x82FA;
		unsigned int GL_TEXTURE_TARGET = 0x1006;
		unsigned int GL_QUERY_TARGET = 0x82EA;
		unsigned int GL_GUILTY_CONTEXT_RESET = 0x8253;
		unsigned int GL_INNOCENT_CONTEXT_RESET = 0x8254;
		unsigned int GL_UNKNOWN_CONTEXT_RESET = 0x8255;
		unsigned int GL_RESET_NOTIFICATION_STRATEGY = 0x8256;
		unsigned int GL_LOSE_CONTEXT_ON_RESET = 0x8252;
		unsigned int GL_NO_RESET_NOTIFICATION = 0x8261;
		unsigned int GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT = 0x00000004;
		unsigned int GL_CONTEXT_RELEASE_BEHAVIOR = 0x82FB;
		unsigned int GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH = 0x82FC;
		unsigned int GL_SHADER_BINARY_FORMAT_SPIR_V = 0x9551;
		unsigned int GL_SPIR_V_BINARY = 0x9552;
		unsigned int GL_PARAMETER_BUFFER = 0x80EE;
		unsigned int GL_PARAMETER_BUFFER_BINDING = 0x80EF;
		unsigned int GL_CONTEXT_FLAG_NO_ERROR_BIT = 0x00000008;
		unsigned int GL_VERTICES_SUBMITTED = 0x82EE;
		unsigned int GL_PRIMITIVES_SUBMITTED = 0x82EF;
		unsigned int GL_VERTEX_SHADER_INVOCATIONS = 0x82F0;
		unsigned int GL_TESS_CONTROL_SHADER_PATCHES = 0x82F1;
		unsigned int GL_TESS_EVALUATION_SHADER_INVOCATIONS = 0x82F2;
		unsigned int GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED = 0x82F3;
		unsigned int GL_FRAGMENT_SHADER_INVOCATIONS = 0x82F4;
		unsigned int GL_COMPUTE_SHADER_INVOCATIONS = 0x82F5;
		unsigned int GL_CLIPPING_INPUT_PRIMITIVES = 0x82F6;
		unsigned int GL_CLIPPING_OUTPUT_PRIMITIVES = 0x82F7;
		unsigned int GL_POLYGON_OFFSET_CLAMP = 0x8E1B;
		unsigned int GL_SPIR_V_EXTENSIONS = 0x9553;
		unsigned int GL_NUM_SPIR_V_EXTENSIONS = 0x9554;
		unsigned int GL_TEXTURE_MAX_ANISOTROPY = 0x84FE;
		unsigned int GL_MAX_TEXTURE_MAX_ANISOTROPY = 0x84FF;
		unsigned int GL_TRANSFORM_FEEDBACK_OVERFLOW = 0x82EC;
		unsigned int GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW = 0x82ED;
		
		namespace procs {
			typedef void (* PFNGLCULLFACE) (GLenum mode);
			typedef void (* PFNGLFRONTFACE) (GLenum mode);
			typedef void (* PFNGLHINT) (GLenum target, GLenum mode);
			typedef void (* PFNGLLINEWIDTH) (GLfloat width);
			typedef void (* PFNGLPOINTSIZE) (GLfloat size);
			typedef void (* PFNGLPOLYGONMODE) (GLenum face, GLenum mode);
			typedef void (* PFNGLSCISSOR) (GLint x, GLint y, GLsizei width, GLsizei height);
			typedef void (* PFNGLTEXPARAMETERF) (GLenum target, GLenum pname, GLfloat param);
			typedef void (* PFNGLTEXPARAMETERFV) (GLenum target, GLenum pname, GLfloat * params);
			typedef void (* PFNGLTEXPARAMETERI) (GLenum target, GLenum pname, GLint param);
			typedef void (* PFNGLTEXPARAMETERIV) (GLenum target, GLenum pname, GLint * params);
			typedef void (* PFNGLTEXIMAGE1D) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels);
			typedef void (* PFNGLTEXIMAGE2D) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels);
			typedef void (* PFNGLDRAWBUFFER) (GLenum buf);
			typedef void (* PFNGLCLEAR) (GLbitfield mask);
			typedef void (* PFNGLCLEARCOLOR) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
			typedef void (* PFNGLCLEARSTENCIL) (GLint s);
			typedef void (* PFNGLCLEARDEPTH) (GLdouble depth);
			typedef void (* PFNGLSTENCILMASK) (GLuint mask);
			typedef void (* PFNGLCOLORMASK) (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
			typedef void (* PFNGLDEPTHMASK) (GLboolean flag);
			typedef void (* PFNGLDISABLE) (GLenum cap);
			typedef void (* PFNGLENABLE) (GLenum cap);
			typedef void (* PFNGLFINISH) ();
			typedef void (* PFNGLFLUSH) ();
			typedef void (* PFNGLBLENDFUNC) (GLenum sfactor, GLenum dfactor);
			typedef void (* PFNGLLOGICOP) (GLenum opcode);
			typedef void (* PFNGLSTENCILFUNC) (GLenum func, GLint ref, GLuint mask);
			typedef void (* PFNGLSTENCILOP) (GLenum fail, GLenum zfail, GLenum zpass);
			typedef void (* PFNGLDEPTHFUNC) (GLenum func);
			typedef void (* PFNGLPIXELSTOREF) (GLenum pname, GLfloat param);
			typedef void (* PFNGLPIXELSTOREI) (GLenum pname, GLint param);
			typedef void (* PFNGLREADBUFFER) (GLenum src);
			typedef void (* PFNGLREADPIXELS) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void * pixels);
			typedef void (* PFNGLGETBOOLEANV) (GLenum pname, GLboolean * data);
			typedef void (* PFNGLGETDOUBLEV) (GLenum pname, GLdouble * data);
			typedef GLenum (* PFNGLGETERROR) ();
			typedef void (* PFNGLGETFLOATV) (GLenum pname, GLfloat * data);
			typedef void (* PFNGLGETINTEGERV) (GLenum pname, GLint * data);
			typedef GLubyte * (* PFNGLGETSTRING) (GLenum name);
			typedef void (* PFNGLGETTEXIMAGE) (GLenum target, GLint level, GLenum format, GLenum type, void * pixels);
			typedef void (* PFNGLGETTEXPARAMETERFV) (GLenum target, GLenum pname, GLfloat * params);
			typedef void (* PFNGLGETTEXPARAMETERIV) (GLenum target, GLenum pname, GLint * params);
			typedef void (* PFNGLGETTEXLEVELPARAMETERFV) (GLenum target, GLint level, GLenum pname, GLfloat * params);
			typedef void (* PFNGLGETTEXLEVELPARAMETERIV) (GLenum target, GLint level, GLenum pname, GLint * params);
			typedef GLboolean (* PFNGLISENABLED) (GLenum cap);
			typedef void (* PFNGLDEPTHRANGE) (GLdouble n, GLdouble f);
			typedef void (* PFNGLVIEWPORT) (GLint x, GLint y, GLsizei width, GLsizei height);
			typedef void (* PFNGLDRAWARRAYS) (GLenum mode, GLint first, GLsizei count);
			typedef void (* PFNGLDRAWELEMENTS) (GLenum mode, GLsizei count, GLenum type, const void * indices);
			typedef void (* PFNGLPOLYGONOFFSET) (GLfloat factor, GLfloat units);
			typedef void (* PFNGLCOPYTEXIMAGE1D) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
			typedef void (* PFNGLCOPYTEXIMAGE2D) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
			typedef void (* PFNGLCOPYTEXSUBIMAGE1D) (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
			typedef void (* PFNGLCOPYTEXSUBIMAGE2D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
			typedef void (* PFNGLTEXSUBIMAGE1D) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels);
			typedef void (* PFNGLTEXSUBIMAGE2D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
			typedef void (* PFNGLBINDTEXTURE) (GLenum target, GLuint texture);
			typedef void (* PFNGLDELETETEXTURES) (GLsizei n, GLuint * textures);
			typedef void (* PFNGLGENTEXTURES) (GLsizei n, GLuint * textures);
			typedef GLboolean (* PFNGLISTEXTURE) (GLuint texture);
			typedef void (* PFNGLDRAWRANGEELEMENTS) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices);
			typedef void (* PFNGLTEXIMAGE3D) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels);
			typedef void (* PFNGLTEXSUBIMAGE3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
			typedef void (* PFNGLCOPYTEXSUBIMAGE3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
			typedef void (* PFNGLACTIVETEXTURE) (GLenum texture);
			typedef void (* PFNGLSAMPLECOVERAGE) (GLfloat value, GLboolean invert);
			typedef void (* PFNGLCOMPRESSEDTEXIMAGE3D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data);
			typedef void (* PFNGLCOMPRESSEDTEXIMAGE2D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data);
			typedef void (* PFNGLCOMPRESSEDTEXIMAGE1D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * data);
			typedef void (* PFNGLCOMPRESSEDTEXSUBIMAGE3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data);
			typedef void (* PFNGLCOMPRESSEDTEXSUBIMAGE2D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data);
			typedef void (* PFNGLCOMPRESSEDTEXSUBIMAGE1D) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data);
			typedef void (* PFNGLGETCOMPRESSEDTEXIMAGE) (GLenum target, GLint level, void * img);
			typedef void (* PFNGLBLENDFUNCSEPARATE) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
			typedef void (* PFNGLMULTIDRAWARRAYS) (GLenum mode, GLint * first, GLsizei * count, GLsizei drawcount);
			typedef void (* PFNGLMULTIDRAWELEMENTS) (GLenum mode, GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount);
			typedef void (* PFNGLPOINTPARAMETERF) (GLenum pname, GLfloat param);
			typedef void (* PFNGLPOINTPARAMETERFV) (GLenum pname, GLfloat * params);
			typedef void (* PFNGLPOINTPARAMETERI) (GLenum pname, GLint param);
			typedef void (* PFNGLPOINTPARAMETERIV) (GLenum pname, GLint * params);
			typedef void (* PFNGLBLENDCOLOR) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
			typedef void (* PFNGLBLENDEQUATION) (GLenum mode);
			typedef void (* PFNGLGENQUERIES) (GLsizei n, GLuint * ids);
			typedef void (* PFNGLDELETEQUERIES) (GLsizei n, GLuint * ids);
			typedef GLboolean (* PFNGLISQUERY) (GLuint id);
			typedef void (* PFNGLBEGINQUERY) (GLenum target, GLuint id);
			typedef void (* PFNGLENDQUERY) (GLenum target);
			typedef void (* PFNGLGETQUERYIV) (GLenum target, GLenum pname, GLint * params);
			typedef void (* PFNGLGETQUERYOBJECTIV) (GLuint id, GLenum pname, GLint * params);
			typedef void (* PFNGLGETQUERYOBJECTUIV) (GLuint id, GLenum pname, GLuint * params);
			typedef void (* PFNGLBINDBUFFER) (GLenum target, GLuint buffer);
			typedef void (* PFNGLDELETEBUFFERS) (GLsizei n, GLuint * buffers);
			typedef void (* PFNGLGENBUFFERS) (GLsizei n, GLuint * buffers);
			typedef GLboolean (* PFNGLISBUFFER) (GLuint buffer);
			typedef void (* PFNGLBUFFERDATA) (GLenum target, GLsizeiptr size, const void * data, GLenum usage);
			typedef void (* PFNGLBUFFERSUBDATA) (GLenum target, GLintptr offset, GLsizeiptr size, const void * data);
			typedef void (* PFNGLGETBUFFERSUBDATA) (GLenum target, GLintptr offset, GLsizeiptr size, void * data);
			typedef void * (* PFNGLMAPBUFFER) (GLenum target, GLenum access);
			typedef GLboolean (* PFNGLUNMAPBUFFER) (GLenum target);
			typedef void (* PFNGLGETBUFFERPARAMETERIV) (GLenum target, GLenum pname, GLint * params);
			typedef void (* PFNGLGETBUFFERPOINTERV) (GLenum target, GLenum pname, void ** params);
			typedef void (* PFNGLBLENDEQUATIONSEPARATE) (GLenum modeRGB, GLenum modeAlpha);
			typedef void (* PFNGLDRAWBUFFERS) (GLsizei n, GLenum * bufs);
			typedef void (* PFNGLSTENCILOPSEPARATE) (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
			typedef void (* PFNGLSTENCILFUNCSEPARATE) (GLenum face, GLenum func, GLint ref, GLuint mask);
			typedef void (* PFNGLSTENCILMASKSEPARATE) (GLenum face, GLuint mask);
			typedef void (* PFNGLATTACHSHADER) (GLuint program, GLuint shader);
			typedef void (* PFNGLBINDATTRIBLOCATION) (GLuint program, GLuint index, GLchar * name);
			typedef void (* PFNGLCOMPILESHADER) (GLuint shader);
			typedef GLuint (* PFNGLCREATEPROGRAM) ();
			typedef GLuint (* PFNGLCREATESHADER) (GLenum type);
			typedef void (* PFNGLDELETEPROGRAM) (GLuint program);
			typedef void (* PFNGLDELETESHADER) (GLuint shader);
			typedef void (* PFNGLDETACHSHADER) (GLuint program, GLuint shader);
			typedef void (* PFNGLDISABLEVERTEXATTRIBARRAY) (GLuint index);
			typedef void (* PFNGLENABLEVERTEXATTRIBARRAY) (GLuint index);
			typedef void (* PFNGLGETACTIVEATTRIB) (GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
			typedef void (* PFNGLGETACTIVEUNIFORM) (GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
			typedef void (* PFNGLGETATTACHEDSHADERS) (GLuint program, GLsizei maxCount, GLsizei * count, GLuint * shaders);
			typedef GLint (* PFNGLGETATTRIBLOCATION) (GLuint program, GLchar * name);
			typedef void (* PFNGLGETPROGRAMIV) (GLuint program, GLenum pname, GLint * params);
			typedef void (* PFNGLGETPROGRAMINFOLOG) (GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
			typedef void (* PFNGLGETSHADERIV) (GLuint shader, GLenum pname, GLint * params);
			typedef void (* PFNGLGETSHADERINFOLOG) (GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
			typedef void (* PFNGLGETSHADERSOURCE) (GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source);
			typedef GLint (* PFNGLGETUNIFORMLOCATION) (GLuint program, GLchar * name);
			typedef void (* PFNGLGETUNIFORMFV) (GLuint program, GLint location, GLfloat * params);
			typedef void (* PFNGLGETUNIFORMIV) (GLuint program, GLint location, GLint * params);
			typedef void (* PFNGLGETVERTEXATTRIBDV) (GLuint index, GLenum pname, GLdouble * params);
			typedef void (* PFNGLGETVERTEXATTRIBFV) (GLuint index, GLenum pname, GLfloat * params);
			typedef void (* PFNGLGETVERTEXATTRIBIV) (GLuint index, GLenum pname, GLint * params);
			typedef void (* PFNGLGETVERTEXATTRIBPOINTERV) (GLuint index, GLenum pname, void ** pointer);
			typedef GLboolean (* PFNGLISPROGRAM) (GLuint program);
			typedef GLboolean (* PFNGLISSHADER) (GLuint shader);
			typedef void (* PFNGLLINKPROGRAM) (GLuint program);
			typedef void (* PFNGLSHADERSOURCE) (GLuint shader, GLsizei count, GLchar *const* string, GLint * length);
			typedef void (* PFNGLUSEPROGRAM) (GLuint program);
			typedef void (* PFNGLUNIFORM1F) (GLint location, GLfloat v0);
			typedef void (* PFNGLUNIFORM2F) (GLint location, GLfloat v0, GLfloat v1);
			typedef void (* PFNGLUNIFORM3F) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
			typedef void (* PFNGLUNIFORM4F) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
			typedef void (* PFNGLUNIFORM1I) (GLint location, GLint v0);
			typedef void (* PFNGLUNIFORM2I) (GLint location, GLint v0, GLint v1);
			typedef void (* PFNGLUNIFORM3I) (GLint location, GLint v0, GLint v1, GLint v2);
			typedef void (* PFNGLUNIFORM4I) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
			typedef void (* PFNGLUNIFORM1FV) (GLint location, GLsizei count, GLfloat * value);
			typedef void (* PFNGLUNIFORM2FV) (GLint location, GLsizei count, GLfloat * value);
			typedef void (* PFNGLUNIFORM3FV) (GLint location, GLsizei count, GLfloat * value);
			typedef void (* PFNGLUNIFORM4FV) (GLint location, GLsizei count, GLfloat * value);
			typedef void (* PFNGLUNIFORM1IV) (GLint location, GLsizei count, GLint * value);
			typedef void (* PFNGLUNIFORM2IV) (GLint location, GLsizei count, GLint * value);
			typedef void (* PFNGLUNIFORM3IV) (GLint location, GLsizei count, GLint * value);
			typedef void (* PFNGLUNIFORM4IV) (GLint location, GLsizei count, GLint * value);
			typedef void (* PFNGLUNIFORMMATRIX2FV) (GLint location, GLsizei count, GLboolean transpose, GLfloat * value);
			typedef void (* PFNGLUNIFORMMATRIX3FV) (GLint location, GLsizei count, GLboolean transpose, GLfloat * value);
			typedef void (* PFNGLUNIFORMMATRIX4FV) (GLint location, GLsizei count, GLboolean transpose, GLfloat * value);
			typedef void (* PFNGLVALIDATEPROGRAM) (GLuint program);
			typedef void (* PFNGLVERTEXATTRIB1D) (GLuint index, GLdouble x);
			typedef void (* PFNGLVERTEXATTRIB1DV) (GLuint index, GLdouble * v);
			typedef void (* PFNGLVERTEXATTRIB1F) (GLuint index, GLfloat x);
			typedef void (* PFNGLVERTEXATTRIB1FV) (GLuint index, GLfloat * v);
			typedef void (* PFNGLVERTEXATTRIB1S) (GLuint index, GLshort x);
			typedef void (* PFNGLVERTEXATTRIB1SV) (GLuint index, GLshort * v);
			typedef void (* PFNGLVERTEXATTRIB2D) (GLuint index, GLdouble x, GLdouble y);
			typedef void (* PFNGLVERTEXATTRIB2DV) (GLuint index, GLdouble * v);
			typedef void (* PFNGLVERTEXATTRIB2F) (GLuint index, GLfloat x, GLfloat y);
			typedef void (* PFNGLVERTEXATTRIB2FV) (GLuint index, GLfloat * v);
			typedef void (* PFNGLVERTEXATTRIB2S) (GLuint index, GLshort x, GLshort y);
			typedef void (* PFNGLVERTEXATTRIB2SV) (GLuint index, GLshort * v);
			typedef void (* PFNGLVERTEXATTRIB3D) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
			typedef void (* PFNGLVERTEXATTRIB3DV) (GLuint index, GLdouble * v);
			typedef void (* PFNGLVERTEXATTRIB3F) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
			typedef void (* PFNGLVERTEXATTRIB3FV) (GLuint index, GLfloat * v);
			typedef void (* PFNGLVERTEXATTRIB3S) (GLuint index, GLshort x, GLshort y, GLshort z);
			typedef void (* PFNGLVERTEXATTRIB3SV) (GLuint index, GLshort * v);
			typedef void (* PFNGLVERTEXATTRIB4NBV) (GLuint index, GLbyte * v);
			typedef void (* PFNGLVERTEXATTRIB4NIV) (GLuint index, GLint * v);
			typedef void (* PFNGLVERTEXATTRIB4NSV) (GLuint index, GLshort * v);
			typedef void (* PFNGLVERTEXATTRIB4NUB) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
			typedef void (* PFNGLVERTEXATTRIB4NUBV) (GLuint index, GLubyte * v);
			typedef void (* PFNGLVERTEXATTRIB4NUIV) (GLuint index, GLuint * v);
			typedef void (* PFNGLVERTEXATTRIB4NUSV) (GLuint index, GLushort * v);
			typedef void (* PFNGLVERTEXATTRIB4BV) (GLuint index, GLbyte * v);
			typedef void (* PFNGLVERTEXATTRIB4D) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
			typedef void (* PFNGLVERTEXATTRIB4DV) (GLuint index, GLdouble * v);
			typedef void (* PFNGLVERTEXATTRIB4F) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
			typedef void (* PFNGLVERTEXATTRIB4FV) (GLuint index, GLfloat * v);
			typedef void (* PFNGLVERTEXATTRIB4IV) (GLuint index, GLint * v);
			typedef void (* PFNGLVERTEXATTRIB4S) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
			typedef void (* PFNGLVERTEXATTRIB4SV) (GLuint index, GLshort * v);
			typedef void (* PFNGLVERTEXATTRIB4UBV) (GLuint index, GLubyte * v);
			typedef void (* PFNGLVERTEXATTRIB4UIV) (GLuint index, GLuint * v);
			typedef void (* PFNGLVERTEXATTRIB4USV) (GLuint index, GLushort * v);
			typedef void (* PFNGLVERTEXATTRIBPOINTER) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer);
			typedef void (* PFNGLUNIFORMMATRIX2X3FV) (GLint location, GLsizei count, GLboolean transpose, GLfloat * value);
			typedef void (* PFNGLUNIFORMMATRIX3X2FV) (GLint location, GLsizei count, GLboolean transpose, GLfloat * value);
			typedef void (* PFNGLUNIFORMMATRIX2X4FV) (GLint location, GLsizei count, GLboolean transpose, GLfloat * value);
			typedef void (* PFNGLUNIFORMMATRIX4X2FV) (GLint location, GLsizei count, GLboolean transpose, GLfloat * value);
			typedef void (* PFNGLUNIFORMMATRIX3X4FV) (GLint location, GLsizei count, GLboolean transpose, GLfloat * value);
			typedef void (* PFNGLUNIFORMMATRIX4X3FV) (GLint location, GLsizei count, GLboolean transpose, GLfloat * value);
			typedef void (* PFNGLCOLORMASKI) (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
			typedef void (* PFNGLGETBOOLEANI_V) (GLenum target, GLuint index, GLboolean * data);
			typedef void (* PFNGLGETINTEGERI_V) (GLenum target, GLuint index, GLint * data);
			typedef void (* PFNGLENABLEI) (GLenum target, GLuint index);
			typedef void (* PFNGLDISABLEI) (GLenum target, GLuint index);
			typedef GLboolean (* PFNGLISENABLEDI) (GLenum target, GLuint index);
			typedef void (* PFNGLBEGINTRANSFORMFEEDBACK) (GLenum primitiveMode);
			typedef void (* PFNGLENDTRANSFORMFEEDBACK) ();
			typedef void (* PFNGLBINDBUFFERRANGE) (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
			typedef void (* PFNGLBINDBUFFERBASE) (GLenum target, GLuint index, GLuint buffer);
			typedef void (* PFNGLTRANSFORMFEEDBACKVARYINGS) (GLuint program, GLsizei count, GLchar *const* varyings, GLenum bufferMode);
			typedef void (* PFNGLGETTRANSFORMFEEDBACKVARYING) (GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name);
			typedef void (* PFNGLCLAMPCOLOR) (GLenum target, GLenum clamp);
			typedef void (* PFNGLBEGINCONDITIONALRENDER) (GLuint id, GLenum mode);
			typedef void (* PFNGLENDCONDITIONALRENDER) ();
			typedef void (* PFNGLVERTEXATTRIBIPOINTER) (GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer);
			typedef void (* PFNGLGETVERTEXATTRIBIIV) (GLuint index, GLenum pname, GLint * params);
			typedef void (* PFNGLGETVERTEXATTRIBIUIV) (GLuint index, GLenum pname, GLuint * params);
			typedef void (* PFNGLVERTEXATTRIBI1I) (GLuint index, GLint x);
			typedef void (* PFNGLVERTEXATTRIBI2I) (GLuint index, GLint x, GLint y);
			typedef void (* PFNGLVERTEXATTRIBI3I) (GLuint index, GLint x, GLint y, GLint z);
			typedef void (* PFNGLVERTEXATTRIBI4I) (GLuint index, GLint x, GLint y, GLint z, GLint w);
			typedef void (* PFNGLVERTEXATTRIBI1UI) (GLuint index, GLuint x);
			typedef void (* PFNGLVERTEXATTRIBI2UI) (GLuint index, GLuint x, GLuint y);
			typedef void (* PFNGLVERTEXATTRIBI3UI) (GLuint index, GLuint x, GLuint y, GLuint z);
			typedef void (* PFNGLVERTEXATTRIBI4UI) (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
			typedef void (* PFNGLVERTEXATTRIBI1IV) (GLuint index, GLint * v);
			typedef void (* PFNGLVERTEXATTRIBI2IV) (GLuint index, GLint * v);
			typedef void (* PFNGLVERTEXATTRIBI3IV) (GLuint index, GLint * v);
			typedef void (* PFNGLVERTEXATTRIBI4IV) (GLuint index, GLint * v);
			typedef void (* PFNGLVERTEXATTRIBI1UIV) (GLuint index, GLuint * v);
			typedef void (* PFNGLVERTEXATTRIBI2UIV) (GLuint index, GLuint * v);
			typedef void (* PFNGLVERTEXATTRIBI3UIV) (GLuint index, GLuint * v);
			typedef void (* PFNGLVERTEXATTRIBI4UIV) (GLuint index, GLuint * v);
			typedef void (* PFNGLVERTEXATTRIBI4BV) (GLuint index, GLbyte * v);
			typedef void (* PFNGLVERTEXATTRIBI4SV) (GLuint index, GLshort * v);
			typedef void (* PFNGLVERTEXATTRIBI4UBV) (GLuint index, GLubyte * v);
			typedef void (* PFNGLVERTEXATTRIBI4USV) (GLuint index, GLushort * v);
			typedef void (* PFNGLGETUNIFORMUIV) (GLuint program, GLint location, GLuint * params);
			typedef void (* PFNGLBINDFRAGDATALOCATION) (GLuint program, GLuint color, GLchar * name);
			typedef GLint (* PFNGLGETFRAGDATALOCATION) (GLuint program, GLchar * name);
			typedef void (* PFNGLUNIFORM1UI) (GLint location, GLuint v0);
			typedef void (* PFNGLUNIFORM2UI) (GLint location, GLuint v0, GLuint v1);
			typedef void (* PFNGLUNIFORM3UI) (GLint location, GLuint v0, GLuint v1, GLuint v2);
			typedef void (* PFNGLUNIFORM4UI) (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
			typedef void (* PFNGLUNIFORM1UIV) (GLint location, GLsizei count, GLuint * value);
			typedef void (* PFNGLUNIFORM2UIV) (GLint location, GLsizei count, GLuint * value);
			typedef void (* PFNGLUNIFORM3UIV) (GLint location, GLsizei count, GLuint * value);
			typedef void (* PFNGLUNIFORM4UIV) (GLint location, GLsizei count, GLuint * value);
			typedef void (* PFNGLTEXPARAMETERIIV) (GLenum target, GLenum pname, GLint * params);
			typedef void (* PFNGLTEXPARAMETERIUIV) (GLenum target, GLenum pname, GLuint * params);
			typedef void (* PFNGLGETTEXPARAMETERIIV) (GLenum target, GLenum pname, GLint * params);
			typedef void (* PFNGLGETTEXPARAMETERIUIV) (GLenum target, GLenum pname, GLuint * params);
			typedef void (* PFNGLCLEARBUFFERIV) (GLenum buffer, GLint drawbuffer, GLint * value);
			typedef void (* PFNGLCLEARBUFFERUIV) (GLenum buffer, GLint drawbuffer, GLuint * value);
			typedef void (* PFNGLCLEARBUFFERFV) (GLenum buffer, GLint drawbuffer, GLfloat * value);
			typedef void (* PFNGLCLEARBUFFERFI) (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
			typedef GLubyte * (* PFNGLGETSTRINGI) (GLenum name, GLuint index);
			typedef GLboolean (* PFNGLISRENDERBUFFER) (GLuint renderbuffer);
			typedef void (* PFNGLBINDRENDERBUFFER) (GLenum target, GLuint renderbuffer);
			typedef void (* PFNGLDELETERENDERBUFFERS) (GLsizei n, GLuint * renderbuffers);
			typedef void (* PFNGLGENRENDERBUFFERS) (GLsizei n, GLuint * renderbuffers);
			typedef void (* PFNGLRENDERBUFFERSTORAGE) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
			typedef void (* PFNGLGETRENDERBUFFERPARAMETERIV) (GLenum target, GLenum pname, GLint * params);
			typedef GLboolean (* PFNGLISFRAMEBUFFER) (GLuint framebuffer);
			typedef void (* PFNGLBINDFRAMEBUFFER) (GLenum target, GLuint framebuffer);
			typedef void (* PFNGLDELETEFRAMEBUFFERS) (GLsizei n, GLuint * framebuffers);
			typedef void (* PFNGLGENFRAMEBUFFERS) (GLsizei n, GLuint * framebuffers);
			typedef GLenum (* PFNGLCHECKFRAMEBUFFERSTATUS) (GLenum target);
			typedef void (* PFNGLFRAMEBUFFERTEXTURE1D) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
			typedef void (* PFNGLFRAMEBUFFERTEXTURE2D) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
			typedef void (* PFNGLFRAMEBUFFERTEXTURE3D) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
			typedef void (* PFNGLFRAMEBUFFERRENDERBUFFER) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
			typedef void (* PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIV) (GLenum target, GLenum attachment, GLenum pname, GLint * params);
			typedef void (* PFNGLGENERATEMIPMAP) (GLenum target);
			typedef void (* PFNGLBLITFRAMEBUFFER) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
			typedef void (* PFNGLRENDERBUFFERSTORAGEMULTISAMPLE) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
			typedef void (* PFNGLFRAMEBUFFERTEXTURELAYER) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
			typedef void * (* PFNGLMAPBUFFERRANGE) (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
			typedef void (* PFNGLFLUSHMAPPEDBUFFERRANGE) (GLenum target, GLintptr offset, GLsizeiptr length);
			typedef void (* PFNGLBINDVERTEXARRAY) (GLuint array);
			typedef void (* PFNGLDELETEVERTEXARRAYS) (GLsizei n, GLuint * arrays);
			typedef void (* PFNGLGENVERTEXARRAYS) (GLsizei n, GLuint * arrays);
			typedef GLboolean (* PFNGLISVERTEXARRAY) (GLuint array);
			typedef void (* PFNGLDRAWARRAYSINSTANCED) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
			typedef void (* PFNGLDRAWELEMENTSINSTANCED) (GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount);
			typedef void (* PFNGLTEXBUFFER) (GLenum target, GLenum internalformat, GLuint buffer);
			typedef void (* PFNGLPRIMITIVERESTARTINDEX) (GLuint index);
			typedef void (* PFNGLCOPYBUFFERSUBDATA) (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
			typedef void (* PFNGLGETUNIFORMINDICES) (GLuint program, GLsizei uniformCount, GLchar *const* uniformNames, GLuint * uniformIndices);
			typedef void (* PFNGLGETACTIVEUNIFORMSIV) (GLuint program, GLsizei uniformCount, GLuint * uniformIndices, GLenum pname, GLint * params);
			typedef void (* PFNGLGETACTIVEUNIFORMNAME) (GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformName);
			typedef GLuint (* PFNGLGETUNIFORMBLOCKINDEX) (GLuint program, GLchar * uniformBlockName);
			typedef void (* PFNGLGETACTIVEUNIFORMBLOCKIV) (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint * params);
			typedef void (* PFNGLGETACTIVEUNIFORMBLOCKNAME) (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformBlockName);
			typedef void (* PFNGLUNIFORMBLOCKBINDING) (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
			typedef void (* PFNGLDRAWELEMENTSBASEVERTEX) (GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex);
			typedef void (* PFNGLDRAWRANGEELEMENTSBASEVERTEX) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex);
			typedef void (* PFNGLDRAWELEMENTSINSTANCEDBASEVERTEX) (GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex);
			typedef void (* PFNGLMULTIDRAWELEMENTSBASEVERTEX) (GLenum mode, GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount, GLint * basevertex);
			typedef void (* PFNGLPROVOKINGVERTEX) (GLenum mode);
			typedef GLsync (* PFNGLFENCESYNC) (GLenum condition, GLbitfield flags);
			typedef GLboolean (* PFNGLISSYNC) (GLsync sync);
			typedef void (* PFNGLDELETESYNC) (GLsync sync);
			typedef GLenum (* PFNGLCLIENTWAITSYNC) (GLsync sync, GLbitfield flags, GLuint64 timeout);
			typedef void (* PFNGLWAITSYNC) (GLsync sync, GLbitfield flags, GLuint64 timeout);
			typedef void (* PFNGLGETINTEGER64V) (GLenum pname, GLint64 * data);
			typedef void (* PFNGLGETSYNCIV) (GLsync sync, GLenum pname, GLsizei bufSize, GLsizei * length, GLint * values);
			typedef void (* PFNGLGETINTEGER64I_V) (GLenum target, GLuint index, GLint64 * data);
			typedef void (* PFNGLGETBUFFERPARAMETERI64V) (GLenum target, GLenum pname, GLint64 * params);
			typedef void (* PFNGLFRAMEBUFFERTEXTURE) (GLenum target, GLenum attachment, GLuint texture, GLint level);
			typedef void (* PFNGLTEXIMAGE2DMULTISAMPLE) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
			typedef void (* PFNGLTEXIMAGE3DMULTISAMPLE) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
			typedef void (* PFNGLGETMULTISAMPLEFV) (GLenum pname, GLuint index, GLfloat * val);
			typedef void (* PFNGLSAMPLEMASKI) (GLuint maskNumber, GLbitfield mask);
			typedef void (* PFNGLBINDFRAGDATALOCATIONINDEXED) (GLuint program, GLuint colorNumber, GLuint index, GLchar * name);
			typedef GLint (* PFNGLGETFRAGDATAINDEX) (GLuint program, GLchar * name);
			typedef void (* PFNGLGENSAMPLERS) (GLsizei count, GLuint * samplers);
			typedef void (* PFNGLDELETESAMPLERS) (GLsizei count, GLuint * samplers);
			typedef GLboolean (* PFNGLISSAMPLER) (GLuint sampler);
			typedef void (* PFNGLBINDSAMPLER) (GLuint unit, GLuint sampler);
			typedef void (* PFNGLSAMPLERPARAMETERI) (GLuint sampler, GLenum pname, GLint param);
			typedef void (* PFNGLSAMPLERPARAMETERIV) (GLuint sampler, GLenum pname, GLint * param);
			typedef void (* PFNGLSAMPLERPARAMETERF) (GLuint sampler, GLenum pname, GLfloat param);
			typedef void (* PFNGLSAMPLERPARAMETERFV) (GLuint sampler, GLenum pname, GLfloat * param);
			typedef void (* PFNGLSAMPLERPARAMETERIIV) (GLuint sampler, GLenum pname, GLint * param);
			typedef void (* PFNGLSAMPLERPARAMETERIUIV) (GLuint sampler, GLenum pname, GLuint * param);
			typedef void (* PFNGLGETSAMPLERPARAMETERIV) (GLuint sampler, GLenum pname, GLint * params);
			typedef void (* PFNGLGETSAMPLERPARAMETERIIV) (GLuint sampler, GLenum pname, GLint * params);
			typedef void (* PFNGLGETSAMPLERPARAMETERFV) (GLuint sampler, GLenum pname, GLfloat * params);
			typedef void (* PFNGLGETSAMPLERPARAMETERIUIV) (GLuint sampler, GLenum pname, GLuint * params);
			typedef void (* PFNGLQUERYCOUNTER) (GLuint id, GLenum target);
			typedef void (* PFNGLGETQUERYOBJECTI64V) (GLuint id, GLenum pname, GLint64 * params);
			typedef void (* PFNGLGETQUERYOBJECTUI64V) (GLuint id, GLenum pname, GLuint64 * params);
			typedef void (* PFNGLVERTEXATTRIBDIVISOR) (GLuint index, GLuint divisor);
			typedef void (* PFNGLVERTEXATTRIBP1UI) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
			typedef void (* PFNGLVERTEXATTRIBP1UIV) (GLuint index, GLenum type, GLboolean normalized, GLuint * value);
			typedef void (* PFNGLVERTEXATTRIBP2UI) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
			typedef void (* PFNGLVERTEXATTRIBP2UIV) (GLuint index, GLenum type, GLboolean normalized, GLuint * value);
			typedef void (* PFNGLVERTEXATTRIBP3UI) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
			typedef void (* PFNGLVERTEXATTRIBP3UIV) (GLuint index, GLenum type, GLboolean normalized, GLuint * value);
			typedef void (* PFNGLVERTEXATTRIBP4UI) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
			typedef void (* PFNGLVERTEXATTRIBP4UIV) (GLuint index, GLenum type, GLboolean normalized, GLuint * value);
			typedef void (* PFNGLVERTEXP2UI) (GLenum type, GLuint value);
			typedef void (* PFNGLVERTEXP2UIV) (GLenum type, GLuint * value);
			typedef void (* PFNGLVERTEXP3UI) (GLenum type, GLuint value);
			typedef void (* PFNGLVERTEXP3UIV) (GLenum type, GLuint * value);
			typedef void (* PFNGLVERTEXP4UI) (GLenum type, GLuint value);
			typedef void (* PFNGLVERTEXP4UIV) (GLenum type, GLuint * value);
			typedef void (* PFNGLTEXCOORDP1UI) (GLenum type, GLuint coords);
			typedef void (* PFNGLTEXCOORDP1UIV) (GLenum type, GLuint * coords);
			typedef void (* PFNGLTEXCOORDP2UI) (GLenum type, GLuint coords);
			typedef void (* PFNGLTEXCOORDP2UIV) (GLenum type, GLuint * coords);
			typedef void (* PFNGLTEXCOORDP3UI) (GLenum type, GLuint coords);
			typedef void (* PFNGLTEXCOORDP3UIV) (GLenum type, GLuint * coords);
			typedef void (* PFNGLTEXCOORDP4UI) (GLenum type, GLuint coords);
			typedef void (* PFNGLTEXCOORDP4UIV) (GLenum type, GLuint * coords);
			typedef void (* PFNGLMULTITEXCOORDP1UI) (GLenum texture, GLenum type, GLuint coords);
			typedef void (* PFNGLMULTITEXCOORDP1UIV) (GLenum texture, GLenum type, GLuint * coords);
			typedef void (* PFNGLMULTITEXCOORDP2UI) (GLenum texture, GLenum type, GLuint coords);
			typedef void (* PFNGLMULTITEXCOORDP2UIV) (GLenum texture, GLenum type, GLuint * coords);
			typedef void (* PFNGLMULTITEXCOORDP3UI) (GLenum texture, GLenum type, GLuint coords);
			typedef void (* PFNGLMULTITEXCOORDP3UIV) (GLenum texture, GLenum type, GLuint * coords);
			typedef void (* PFNGLMULTITEXCOORDP4UI) (GLenum texture, GLenum type, GLuint coords);
			typedef void (* PFNGLMULTITEXCOORDP4UIV) (GLenum texture, GLenum type, GLuint * coords);
			typedef void (* PFNGLNORMALP3UI) (GLenum type, GLuint coords);
			typedef void (* PFNGLNORMALP3UIV) (GLenum type, GLuint * coords);
			typedef void (* PFNGLCOLORP3UI) (GLenum type, GLuint color);
			typedef void (* PFNGLCOLORP3UIV) (GLenum type, GLuint * color);
			typedef void (* PFNGLCOLORP4UI) (GLenum type, GLuint color);
			typedef void (* PFNGLCOLORP4UIV) (GLenum type, GLuint * color);
			typedef void (* PFNGLSECONDARYCOLORP3UI) (GLenum type, GLuint color);
			typedef void (* PFNGLSECONDARYCOLORP3UIV) (GLenum type, GLuint * color);
			typedef void (* PFNGLMINSAMPLESHADING) (GLfloat value);
			typedef void (* PFNGLBLENDEQUATIONI) (GLuint buf, GLenum mode);
			typedef void (* PFNGLBLENDEQUATIONSEPARATEI) (GLuint buf, GLenum modeRGB, GLenum modeAlpha);
			typedef void (* PFNGLBLENDFUNCI) (GLuint buf, GLenum src, GLenum dst);
			typedef void (* PFNGLBLENDFUNCSEPARATEI) (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
			typedef void (* PFNGLDRAWARRAYSINDIRECT) (GLenum mode, const void * indirect);
			typedef void (* PFNGLDRAWELEMENTSINDIRECT) (GLenum mode, GLenum type, const void * indirect);
			typedef void (* PFNGLUNIFORM1D) (GLint location, GLdouble x);
			typedef void (* PFNGLUNIFORM2D) (GLint location, GLdouble x, GLdouble y);
			typedef void (* PFNGLUNIFORM3D) (GLint location, GLdouble x, GLdouble y, GLdouble z);
			typedef void (* PFNGLUNIFORM4D) (GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
			typedef void (* PFNGLUNIFORM1DV) (GLint location, GLsizei count, GLdouble * value);
			typedef void (* PFNGLUNIFORM2DV) (GLint location, GLsizei count, GLdouble * value);
			typedef void (* PFNGLUNIFORM3DV) (GLint location, GLsizei count, GLdouble * value);
			typedef void (* PFNGLUNIFORM4DV) (GLint location, GLsizei count, GLdouble * value);
			typedef void (* PFNGLUNIFORMMATRIX2DV) (GLint location, GLsizei count, GLboolean transpose, GLdouble * value);
			typedef void (* PFNGLUNIFORMMATRIX3DV) (GLint location, GLsizei count, GLboolean transpose, GLdouble * value);
			typedef void (* PFNGLUNIFORMMATRIX4DV) (GLint location, GLsizei count, GLboolean transpose, GLdouble * value);
			typedef void (* PFNGLUNIFORMMATRIX2X3DV) (GLint location, GLsizei count, GLboolean transpose, GLdouble * value);
			typedef void (* PFNGLUNIFORMMATRIX2X4DV) (GLint location, GLsizei count, GLboolean transpose, GLdouble * value);
			typedef void (* PFNGLUNIFORMMATRIX3X2DV) (GLint location, GLsizei count, GLboolean transpose, GLdouble * value);
			typedef void (* PFNGLUNIFORMMATRIX3X4DV) (GLint location, GLsizei count, GLboolean transpose, GLdouble * value);
			typedef void (* PFNGLUNIFORMMATRIX4X2DV) (GLint location, GLsizei count, GLboolean transpose, GLdouble * value);
			typedef void (* PFNGLUNIFORMMATRIX4X3DV) (GLint location, GLsizei count, GLboolean transpose, GLdouble * value);
			typedef void (* PFNGLGETUNIFORMDV) (GLuint program, GLint location, GLdouble * params);
			typedef GLint (* PFNGLGETSUBROUTINEUNIFORMLOCATION) (GLuint program, GLenum shadertype, GLchar * name);
			typedef GLuint (* PFNGLGETSUBROUTINEINDEX) (GLuint program, GLenum shadertype, GLchar * name);
			typedef void (* PFNGLGETACTIVESUBROUTINEUNIFORMIV) (GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint * values);
			typedef void (* PFNGLGETACTIVESUBROUTINEUNIFORMNAME) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei * length, GLchar * name);
			typedef void (* PFNGLGETACTIVESUBROUTINENAME) (GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei * length, GLchar * name);
			typedef void (* PFNGLUNIFORMSUBROUTINESUIV) (GLenum shadertype, GLsizei count, GLuint * indices);
			typedef void (* PFNGLGETUNIFORMSUBROUTINEUIV) (GLenum shadertype, GLint location, GLuint * params);
			typedef void (* PFNGLGETPROGRAMSTAGEIV) (GLuint program, GLenum shadertype, GLenum pname, GLint * values);
			typedef void (* PFNGLPATCHPARAMETERI) (GLenum pname, GLint value);
			typedef void (* PFNGLPATCHPARAMETERFV) (GLenum pname, GLfloat * values);
			typedef void (* PFNGLBINDTRANSFORMFEEDBACK) (GLenum target, GLuint id);
			typedef void (* PFNGLDELETETRANSFORMFEEDBACKS) (GLsizei n, GLuint * ids);
			typedef void (* PFNGLGENTRANSFORMFEEDBACKS) (GLsizei n, GLuint * ids);
			typedef GLboolean (* PFNGLISTRANSFORMFEEDBACK) (GLuint id);
			typedef void (* PFNGLPAUSETRANSFORMFEEDBACK) ();
			typedef void (* PFNGLRESUMETRANSFORMFEEDBACK) ();
			typedef void (* PFNGLDRAWTRANSFORMFEEDBACK) (GLenum mode, GLuint id);
			typedef void (* PFNGLDRAWTRANSFORMFEEDBACKSTREAM) (GLenum mode, GLuint id, GLuint stream);
			typedef void (* PFNGLBEGINQUERYINDEXED) (GLenum target, GLuint index, GLuint id);
			typedef void (* PFNGLENDQUERYINDEXED) (GLenum target, GLuint index);
			typedef void (* PFNGLGETQUERYINDEXEDIV) (GLenum target, GLuint index, GLenum pname, GLint * params);
			typedef void (* PFNGLRELEASESHADERCOMPILER) ();
			typedef void (* PFNGLSHADERBINARY) (GLsizei count, GLuint * shaders, GLenum binaryformat, const void * binary, GLsizei length);
			typedef void (* PFNGLGETSHADERPRECISIONFORMAT) (GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision);
			typedef void (* PFNGLDEPTHRANGEF) (GLfloat n, GLfloat f);
			typedef void (* PFNGLCLEARDEPTHF) (GLfloat d);
			typedef void (* PFNGLGETPROGRAMBINARY) (GLuint program, GLsizei bufSize, GLsizei * length, GLenum * binaryFormat, void * binary);
			typedef void (* PFNGLPROGRAMBINARY) (GLuint program, GLenum binaryFormat, const void * binary, GLsizei length);
			typedef void (* PFNGLPROGRAMPARAMETERI) (GLuint program, GLenum pname, GLint value);
			typedef void (* PFNGLUSEPROGRAMSTAGES) (GLuint pipeline, GLbitfield stages, GLuint program);
			typedef void (* PFNGLACTIVESHADERPROGRAM) (GLuint pipeline, GLuint program);
			typedef GLuint (* PFNGLCREATESHADERPROGRAMV) (GLenum type, GLsizei count, GLchar *const* strings);
			typedef void (* PFNGLBINDPROGRAMPIPELINE) (GLuint pipeline);
			typedef void (* PFNGLDELETEPROGRAMPIPELINES) (GLsizei n, GLuint * pipelines);
			typedef void (* PFNGLGENPROGRAMPIPELINES) (GLsizei n, GLuint * pipelines);
			typedef GLboolean (* PFNGLISPROGRAMPIPELINE) (GLuint pipeline);
			typedef void (* PFNGLGETPROGRAMPIPELINEIV) (GLuint pipeline, GLenum pname, GLint * params);
			typedef void (* PFNGLPROGRAMUNIFORM1I) (GLuint program, GLint location, GLint v0);
			typedef void (* PFNGLPROGRAMUNIFORM1IV) (GLuint program, GLint location, GLsizei count, GLint * value);
			typedef void (* PFNGLPROGRAMUNIFORM1F) (GLuint program, GLint location, GLfloat v0);
			typedef void (* PFNGLPROGRAMUNIFORM1FV) (GLuint program, GLint location, GLsizei count, GLfloat * value);
			typedef void (* PFNGLPROGRAMUNIFORM1D) (GLuint program, GLint location, GLdouble v0);
			typedef void (* PFNGLPROGRAMUNIFORM1DV) (GLuint program, GLint location, GLsizei count, GLdouble * value);
			typedef void (* PFNGLPROGRAMUNIFORM1UI) (GLuint program, GLint location, GLuint v0);
			typedef void (* PFNGLPROGRAMUNIFORM1UIV) (GLuint program, GLint location, GLsizei count, GLuint * value);
			typedef void (* PFNGLPROGRAMUNIFORM2I) (GLuint program, GLint location, GLint v0, GLint v1);
			typedef void (* PFNGLPROGRAMUNIFORM2IV) (GLuint program, GLint location, GLsizei count, GLint * value);
			typedef void (* PFNGLPROGRAMUNIFORM2F) (GLuint program, GLint location, GLfloat v0, GLfloat v1);
			typedef void (* PFNGLPROGRAMUNIFORM2FV) (GLuint program, GLint location, GLsizei count, GLfloat * value);
			typedef void (* PFNGLPROGRAMUNIFORM2D) (GLuint program, GLint location, GLdouble v0, GLdouble v1);
			typedef void (* PFNGLPROGRAMUNIFORM2DV) (GLuint program, GLint location, GLsizei count, GLdouble * value);
			typedef void (* PFNGLPROGRAMUNIFORM2UI) (GLuint program, GLint location, GLuint v0, GLuint v1);
			typedef void (* PFNGLPROGRAMUNIFORM2UIV) (GLuint program, GLint location, GLsizei count, GLuint * value);
			typedef void (* PFNGLPROGRAMUNIFORM3I) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
			typedef void (* PFNGLPROGRAMUNIFORM3IV) (GLuint program, GLint location, GLsizei count, GLint * value);
			typedef void (* PFNGLPROGRAMUNIFORM3F) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
			typedef void (* PFNGLPROGRAMUNIFORM3FV) (GLuint program, GLint location, GLsizei count, GLfloat * value);
			typedef void (* PFNGLPROGRAMUNIFORM3D) (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
			typedef void (* PFNGLPROGRAMUNIFORM3DV) (GLuint program, GLint location, GLsizei count, GLdouble * value);
			typedef void (* PFNGLPROGRAMUNIFORM3UI) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
			typedef void (* PFNGLPROGRAMUNIFORM3UIV) (GLuint program, GLint location, GLsizei count, GLuint * value);
			typedef void (* PFNGLPROGRAMUNIFORM4I) (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
			typedef void (* PFNGLPROGRAMUNIFORM4IV) (GLuint program, GLint location, GLsizei count, GLint * value);
			typedef void (* PFNGLPROGRAMUNIFORM4F) (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
			typedef void (* PFNGLPROGRAMUNIFORM4FV) (GLuint program, GLint location, GLsizei count, GLfloat * value);
			typedef void (* PFNGLPROGRAMUNIFORM4D) (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
			typedef void (* PFNGLPROGRAMUNIFORM4DV) (GLuint program, GLint location, GLsizei count, GLdouble * value);
			typedef void (* PFNGLPROGRAMUNIFORM4UI) (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
			typedef void (* PFNGLPROGRAMUNIFORM4UIV) (GLuint program, GLint location, GLsizei count, GLuint * value);
			typedef void (* PFNGLPROGRAMUNIFORMMATRIX2FV) (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat * value);
			typedef void (* PFNGLPROGRAMUNIFORMMATRIX3FV) (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat * value);
			typedef void (* PFNGLPROGRAMUNIFORMMATRIX4FV) (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat * value);
			typedef void (* PFNGLPROGRAMUNIFORMMATRIX2DV) (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble * value);
			typedef void (* PFNGLPROGRAMUNIFORMMATRIX3DV) (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble * value);
			typedef void (* PFNGLPROGRAMUNIFORMMATRIX4DV) (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble * value);
			typedef void (* PFNGLPROGRAMUNIFORMMATRIX2X3FV) (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat * value);
			typedef void (* PFNGLPROGRAMUNIFORMMATRIX3X2FV) (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat * value);
			typedef void (* PFNGLPROGRAMUNIFORMMATRIX2X4FV) (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat * value);
			typedef void (* PFNGLPROGRAMUNIFORMMATRIX4X2FV) (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat * value);
			typedef void (* PFNGLPROGRAMUNIFORMMATRIX3X4FV) (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat * value);
			typedef void (* PFNGLPROGRAMUNIFORMMATRIX4X3FV) (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat * value);
			typedef void (* PFNGLPROGRAMUNIFORMMATRIX2X3DV) (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble * value);
			typedef void (* PFNGLPROGRAMUNIFORMMATRIX3X2DV) (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble * value);
			typedef void (* PFNGLPROGRAMUNIFORMMATRIX2X4DV) (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble * value);
			typedef void (* PFNGLPROGRAMUNIFORMMATRIX4X2DV) (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble * value);
			typedef void (* PFNGLPROGRAMUNIFORMMATRIX3X4DV) (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble * value);
			typedef void (* PFNGLPROGRAMUNIFORMMATRIX4X3DV) (GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble * value);
			typedef void (* PFNGLVALIDATEPROGRAMPIPELINE) (GLuint pipeline);
			typedef void (* PFNGLGETPROGRAMPIPELINEINFOLOG) (GLuint pipeline, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
			typedef void (* PFNGLVERTEXATTRIBL1D) (GLuint index, GLdouble x);
			typedef void (* PFNGLVERTEXATTRIBL2D) (GLuint index, GLdouble x, GLdouble y);
			typedef void (* PFNGLVERTEXATTRIBL3D) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
			typedef void (* PFNGLVERTEXATTRIBL4D) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
			typedef void (* PFNGLVERTEXATTRIBL1DV) (GLuint index, GLdouble * v);
			typedef void (* PFNGLVERTEXATTRIBL2DV) (GLuint index, GLdouble * v);
			typedef void (* PFNGLVERTEXATTRIBL3DV) (GLuint index, GLdouble * v);
			typedef void (* PFNGLVERTEXATTRIBL4DV) (GLuint index, GLdouble * v);
			typedef void (* PFNGLVERTEXATTRIBLPOINTER) (GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer);
			typedef void (* PFNGLGETVERTEXATTRIBLDV) (GLuint index, GLenum pname, GLdouble * params);
			typedef void (* PFNGLVIEWPORTARRAYV) (GLuint first, GLsizei count, GLfloat * v);
			typedef void (* PFNGLVIEWPORTINDEXEDF) (GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
			typedef void (* PFNGLVIEWPORTINDEXEDFV) (GLuint index, GLfloat * v);
			typedef void (* PFNGLSCISSORARRAYV) (GLuint first, GLsizei count, GLint * v);
			typedef void (* PFNGLSCISSORINDEXED) (GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
			typedef void (* PFNGLSCISSORINDEXEDV) (GLuint index, GLint * v);
			typedef void (* PFNGLDEPTHRANGEARRAYV) (GLuint first, GLsizei count, GLdouble * v);
			typedef void (* PFNGLDEPTHRANGEINDEXED) (GLuint index, GLdouble n, GLdouble f);
			typedef void (* PFNGLGETFLOATI_V) (GLenum target, GLuint index, GLfloat * data);
			typedef void (* PFNGLGETDOUBLEI_V) (GLenum target, GLuint index, GLdouble * data);
			typedef void (* PFNGLDRAWARRAYSINSTANCEDBASEINSTANCE) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
			typedef void (* PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCE) (GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLuint baseinstance);
			typedef void (* PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCE) (GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
			typedef void (* PFNGLGETINTERNALFORMATIV) (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint * params);
			typedef void (* PFNGLGETACTIVEATOMICCOUNTERBUFFERIV) (GLuint program, GLuint bufferIndex, GLenum pname, GLint * params);
			typedef void (* PFNGLBINDIMAGETEXTURE) (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
			typedef void (* PFNGLMEMORYBARRIER) (GLbitfield barriers);
			typedef void (* PFNGLTEXSTORAGE1D) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
			typedef void (* PFNGLTEXSTORAGE2D) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
			typedef void (* PFNGLTEXSTORAGE3D) (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
			typedef void (* PFNGLDRAWTRANSFORMFEEDBACKINSTANCED) (GLenum mode, GLuint id, GLsizei instancecount);
			typedef void (* PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCED) (GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
			typedef void (* PFNGLCLEARBUFFERDATA) (GLenum target, GLenum internalformat, GLenum format, GLenum type, const void * data);
			typedef void (* PFNGLCLEARBUFFERSUBDATA) (GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data);
			typedef void (* PFNGLDISPATCHCOMPUTE) (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
			typedef void (* PFNGLDISPATCHCOMPUTEINDIRECT) (GLintptr indirect);
			typedef void (* PFNGLCOPYIMAGESUBDATA) (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
			typedef void (* PFNGLFRAMEBUFFERPARAMETERI) (GLenum target, GLenum pname, GLint param);
			typedef void (* PFNGLGETFRAMEBUFFERPARAMETERIV) (GLenum target, GLenum pname, GLint * params);
			typedef void (* PFNGLGETINTERNALFORMATI64V) (GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 * params);
			typedef void (* PFNGLINVALIDATETEXSUBIMAGE) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
			typedef void (* PFNGLINVALIDATETEXIMAGE) (GLuint texture, GLint level);
			typedef void (* PFNGLINVALIDATEBUFFERSUBDATA) (GLuint buffer, GLintptr offset, GLsizeiptr length);
			typedef void (* PFNGLINVALIDATEBUFFERDATA) (GLuint buffer);
			typedef void (* PFNGLINVALIDATEFRAMEBUFFER) (GLenum target, GLsizei numAttachments, GLenum * attachments);
			typedef void (* PFNGLINVALIDATESUBFRAMEBUFFER) (GLenum target, GLsizei numAttachments, GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height);
			typedef void (* PFNGLMULTIDRAWARRAYSINDIRECT) (GLenum mode, const void * indirect, GLsizei drawcount, GLsizei stride);
			typedef void (* PFNGLMULTIDRAWELEMENTSINDIRECT) (GLenum mode, GLenum type, const void * indirect, GLsizei drawcount, GLsizei stride);
			typedef void (* PFNGLGETPROGRAMINTERFACEIV) (GLuint program, GLenum programInterface, GLenum pname, GLint * params);
			typedef GLuint (* PFNGLGETPROGRAMRESOURCEINDEX) (GLuint program, GLenum programInterface, GLchar * name);
			typedef void (* PFNGLGETPROGRAMRESOURCENAME) (GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name);
			typedef void (* PFNGLGETPROGRAMRESOURCEIV) (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, GLenum * props, GLsizei bufSize, GLsizei * length, GLint * params);
			typedef GLint (* PFNGLGETPROGRAMRESOURCELOCATION) (GLuint program, GLenum programInterface, GLchar * name);
			typedef GLint (* PFNGLGETPROGRAMRESOURCELOCATIONINDEX) (GLuint program, GLenum programInterface, GLchar * name);
			typedef void (* PFNGLSHADERSTORAGEBLOCKBINDING) (GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
			typedef void (* PFNGLTEXBUFFERRANGE) (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
			typedef void (* PFNGLTEXSTORAGE2DMULTISAMPLE) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
			typedef void (* PFNGLTEXSTORAGE3DMULTISAMPLE) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
			typedef void (* PFNGLTEXTUREVIEW) (GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
			typedef void (* PFNGLBINDVERTEXBUFFER) (GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
			typedef void (* PFNGLVERTEXATTRIBFORMAT) (GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
			typedef void (* PFNGLVERTEXATTRIBIFORMAT) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
			typedef void (* PFNGLVERTEXATTRIBLFORMAT) (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
			typedef void (* PFNGLVERTEXATTRIBBINDING) (GLuint attribindex, GLuint bindingindex);
			typedef void (* PFNGLVERTEXBINDINGDIVISOR) (GLuint bindingindex, GLuint divisor);
			typedef void (* PFNGLDEBUGMESSAGECONTROL) (GLenum source, GLenum type, GLenum severity, GLsizei count, GLuint * ids, GLboolean enabled);
			typedef void (* PFNGLDEBUGMESSAGEINSERT) (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, GLchar * buf);
			typedef void (* PFNGLDEBUGMESSAGECALLBACK) (GLDEBUGPROC callback, const void * userParam);
			typedef GLuint (* PFNGLGETDEBUGMESSAGELOG) (GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog);
			typedef void (* PFNGLPUSHDEBUGGROUP) (GLenum source, GLuint id, GLsizei length, GLchar * message);
			typedef void (* PFNGLPOPDEBUGGROUP) ();
			typedef void (* PFNGLOBJECTLABEL) (GLenum identifier, GLuint name, GLsizei length, GLchar * label);
			typedef void (* PFNGLGETOBJECTLABEL) (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei * length, GLchar * label);
			typedef void (* PFNGLOBJECTPTRLABEL) (const void * ptr, GLsizei length, GLchar * label);
			typedef void (* PFNGLGETOBJECTPTRLABEL) (const void * ptr, GLsizei bufSize, GLsizei * length, GLchar * label);
			typedef void (* PFNGLGETPOINTERV) (GLenum pname, void ** params);
			typedef void (* PFNGLBUFFERSTORAGE) (GLenum target, GLsizeiptr size, const void * data, GLbitfield flags);
			typedef void (* PFNGLCLEARTEXIMAGE) (GLuint texture, GLint level, GLenum format, GLenum type, const void * data);
			typedef void (* PFNGLCLEARTEXSUBIMAGE) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * data);
			typedef void (* PFNGLBINDBUFFERSBASE) (GLenum target, GLuint first, GLsizei count, GLuint * buffers);
			typedef void (* PFNGLBINDBUFFERSRANGE) (GLenum target, GLuint first, GLsizei count, GLuint * buffers, GLintptr * offsets, GLsizeiptr * sizes);
			typedef void (* PFNGLBINDTEXTURES) (GLuint first, GLsizei count, GLuint * textures);
			typedef void (* PFNGLBINDSAMPLERS) (GLuint first, GLsizei count, GLuint * samplers);
			typedef void (* PFNGLBINDIMAGETEXTURES) (GLuint first, GLsizei count, GLuint * textures);
			typedef void (* PFNGLBINDVERTEXBUFFERS) (GLuint first, GLsizei count, GLuint * buffers, GLintptr * offsets, GLsizei * strides);
			typedef void (* PFNGLCLIPCONTROL) (GLenum origin, GLenum depth);
			typedef void (* PFNGLCREATETRANSFORMFEEDBACKS) (GLsizei n, GLuint * ids);
			typedef void (* PFNGLTRANSFORMFEEDBACKBUFFERBASE) (GLuint xfb, GLuint index, GLuint buffer);
			typedef void (* PFNGLTRANSFORMFEEDBACKBUFFERRANGE) (GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
			typedef void (* PFNGLGETTRANSFORMFEEDBACKIV) (GLuint xfb, GLenum pname, GLint * param);
			typedef void (* PFNGLGETTRANSFORMFEEDBACKI_V) (GLuint xfb, GLenum pname, GLuint index, GLint * param);
			typedef void (* PFNGLGETTRANSFORMFEEDBACKI64_V) (GLuint xfb, GLenum pname, GLuint index, GLint64 * param);
			typedef void (* PFNGLCREATEBUFFERS) (GLsizei n, GLuint * buffers);
			typedef void (* PFNGLNAMEDBUFFERSTORAGE) (GLuint buffer, GLsizeiptr size, const void * data, GLbitfield flags);
			typedef void (* PFNGLNAMEDBUFFERDATA) (GLuint buffer, GLsizeiptr size, const void * data, GLenum usage);
			typedef void (* PFNGLNAMEDBUFFERSUBDATA) (GLuint buffer, GLintptr offset, GLsizeiptr size, const void * data);
			typedef void (* PFNGLCOPYNAMEDBUFFERSUBDATA) (GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
			typedef void (* PFNGLCLEARNAMEDBUFFERDATA) (GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void * data);
			typedef void (* PFNGLCLEARNAMEDBUFFERSUBDATA) (GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data);
			typedef void * (* PFNGLMAPNAMEDBUFFER) (GLuint buffer, GLenum access);
			typedef void * (* PFNGLMAPNAMEDBUFFERRANGE) (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
			typedef GLboolean (* PFNGLUNMAPNAMEDBUFFER) (GLuint buffer);
			typedef void (* PFNGLFLUSHMAPPEDNAMEDBUFFERRANGE) (GLuint buffer, GLintptr offset, GLsizeiptr length);
			typedef void (* PFNGLGETNAMEDBUFFERPARAMETERIV) (GLuint buffer, GLenum pname, GLint * params);
			typedef void (* PFNGLGETNAMEDBUFFERPARAMETERI64V) (GLuint buffer, GLenum pname, GLint64 * params);
			typedef void (* PFNGLGETNAMEDBUFFERPOINTERV) (GLuint buffer, GLenum pname, void ** params);
			typedef void (* PFNGLGETNAMEDBUFFERSUBDATA) (GLuint buffer, GLintptr offset, GLsizeiptr size, void * data);
			typedef void (* PFNGLCREATEFRAMEBUFFERS) (GLsizei n, GLuint * framebuffers);
			typedef void (* PFNGLNAMEDFRAMEBUFFERRENDERBUFFER) (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
			typedef void (* PFNGLNAMEDFRAMEBUFFERPARAMETERI) (GLuint framebuffer, GLenum pname, GLint param);
			typedef void (* PFNGLNAMEDFRAMEBUFFERTEXTURE) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
			typedef void (* PFNGLNAMEDFRAMEBUFFERTEXTURELAYER) (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
			typedef void (* PFNGLNAMEDFRAMEBUFFERDRAWBUFFER) (GLuint framebuffer, GLenum buf);
			typedef void (* PFNGLNAMEDFRAMEBUFFERDRAWBUFFERS) (GLuint framebuffer, GLsizei n, GLenum * bufs);
			typedef void (* PFNGLNAMEDFRAMEBUFFERREADBUFFER) (GLuint framebuffer, GLenum src);
			typedef void (* PFNGLINVALIDATENAMEDFRAMEBUFFERDATA) (GLuint framebuffer, GLsizei numAttachments, GLenum * attachments);
			typedef void (* PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATA) (GLuint framebuffer, GLsizei numAttachments, GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height);
			typedef void (* PFNGLCLEARNAMEDFRAMEBUFFERIV) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLint * value);
			typedef void (* PFNGLCLEARNAMEDFRAMEBUFFERUIV) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLuint * value);
			typedef void (* PFNGLCLEARNAMEDFRAMEBUFFERFV) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat * value);
			typedef void (* PFNGLCLEARNAMEDFRAMEBUFFERFI) (GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
			typedef void (* PFNGLBLITNAMEDFRAMEBUFFER) (GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
			typedef GLenum (* PFNGLCHECKNAMEDFRAMEBUFFERSTATUS) (GLuint framebuffer, GLenum target);
			typedef void (* PFNGLGETNAMEDFRAMEBUFFERPARAMETERIV) (GLuint framebuffer, GLenum pname, GLint * param);
			typedef void (* PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIV) (GLuint framebuffer, GLenum attachment, GLenum pname, GLint * params);
			typedef void (* PFNGLCREATERENDERBUFFERS) (GLsizei n, GLuint * renderbuffers);
			typedef void (* PFNGLNAMEDRENDERBUFFERSTORAGE) (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
			typedef void (* PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLE) (GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
			typedef void (* PFNGLGETNAMEDRENDERBUFFERPARAMETERIV) (GLuint renderbuffer, GLenum pname, GLint * params);
			typedef void (* PFNGLCREATETEXTURES) (GLenum target, GLsizei n, GLuint * textures);
			typedef void (* PFNGLTEXTUREBUFFER) (GLuint texture, GLenum internalformat, GLuint buffer);
			typedef void (* PFNGLTEXTUREBUFFERRANGE) (GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
			typedef void (* PFNGLTEXTURESTORAGE1D) (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
			typedef void (* PFNGLTEXTURESTORAGE2D) (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
			typedef void (* PFNGLTEXTURESTORAGE3D) (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
			typedef void (* PFNGLTEXTURESTORAGE2DMULTISAMPLE) (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
			typedef void (* PFNGLTEXTURESTORAGE3DMULTISAMPLE) (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
			typedef void (* PFNGLTEXTURESUBIMAGE1D) (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels);
			typedef void (* PFNGLTEXTURESUBIMAGE2D) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
			typedef void (* PFNGLTEXTURESUBIMAGE3D) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
			typedef void (* PFNGLCOMPRESSEDTEXTURESUBIMAGE1D) (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data);
			typedef void (* PFNGLCOMPRESSEDTEXTURESUBIMAGE2D) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data);
			typedef void (* PFNGLCOMPRESSEDTEXTURESUBIMAGE3D) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data);
			typedef void (* PFNGLCOPYTEXTURESUBIMAGE1D) (GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
			typedef void (* PFNGLCOPYTEXTURESUBIMAGE2D) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
			typedef void (* PFNGLCOPYTEXTURESUBIMAGE3D) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
			typedef void (* PFNGLTEXTUREPARAMETERF) (GLuint texture, GLenum pname, GLfloat param);
			typedef void (* PFNGLTEXTUREPARAMETERFV) (GLuint texture, GLenum pname, GLfloat * param);
			typedef void (* PFNGLTEXTUREPARAMETERI) (GLuint texture, GLenum pname, GLint param);
			typedef void (* PFNGLTEXTUREPARAMETERIIV) (GLuint texture, GLenum pname, GLint * params);
			typedef void (* PFNGLTEXTUREPARAMETERIUIV) (GLuint texture, GLenum pname, GLuint * params);
			typedef void (* PFNGLTEXTUREPARAMETERIV) (GLuint texture, GLenum pname, GLint * param);
			typedef void (* PFNGLGENERATETEXTUREMIPMAP) (GLuint texture);
			typedef void (* PFNGLBINDTEXTUREUNIT) (GLuint unit, GLuint texture);
			typedef void (* PFNGLGETTEXTUREIMAGE) (GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * pixels);
			typedef void (* PFNGLGETCOMPRESSEDTEXTUREIMAGE) (GLuint texture, GLint level, GLsizei bufSize, void * pixels);
			typedef void (* PFNGLGETTEXTURELEVELPARAMETERFV) (GLuint texture, GLint level, GLenum pname, GLfloat * params);
			typedef void (* PFNGLGETTEXTURELEVELPARAMETERIV) (GLuint texture, GLint level, GLenum pname, GLint * params);
			typedef void (* PFNGLGETTEXTUREPARAMETERFV) (GLuint texture, GLenum pname, GLfloat * params);
			typedef void (* PFNGLGETTEXTUREPARAMETERIIV) (GLuint texture, GLenum pname, GLint * params);
			typedef void (* PFNGLGETTEXTUREPARAMETERIUIV) (GLuint texture, GLenum pname, GLuint * params);
			typedef void (* PFNGLGETTEXTUREPARAMETERIV) (GLuint texture, GLenum pname, GLint * params);
			typedef void (* PFNGLCREATEVERTEXARRAYS) (GLsizei n, GLuint * arrays);
			typedef void (* PFNGLDISABLEVERTEXARRAYATTRIB) (GLuint vaobj, GLuint index);
			typedef void (* PFNGLENABLEVERTEXARRAYATTRIB) (GLuint vaobj, GLuint index);
			typedef void (* PFNGLVERTEXARRAYELEMENTBUFFER) (GLuint vaobj, GLuint buffer);
			typedef void (* PFNGLVERTEXARRAYVERTEXBUFFER) (GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
			typedef void (* PFNGLVERTEXARRAYVERTEXBUFFERS) (GLuint vaobj, GLuint first, GLsizei count, GLuint * buffers, GLintptr * offsets, GLsizei * strides);
			typedef void (* PFNGLVERTEXARRAYATTRIBBINDING) (GLuint vaobj, GLuint attribindex, GLuint bindingindex);
			typedef void (* PFNGLVERTEXARRAYATTRIBFORMAT) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
			typedef void (* PFNGLVERTEXARRAYATTRIBIFORMAT) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
			typedef void (* PFNGLVERTEXARRAYATTRIBLFORMAT) (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
			typedef void (* PFNGLVERTEXARRAYBINDINGDIVISOR) (GLuint vaobj, GLuint bindingindex, GLuint divisor);
			typedef void (* PFNGLGETVERTEXARRAYIV) (GLuint vaobj, GLenum pname, GLint * param);
			typedef void (* PFNGLGETVERTEXARRAYINDEXEDIV) (GLuint vaobj, GLuint index, GLenum pname, GLint * param);
			typedef void (* PFNGLGETVERTEXARRAYINDEXED64IV) (GLuint vaobj, GLuint index, GLenum pname, GLint64 * param);
			typedef void (* PFNGLCREATESAMPLERS) (GLsizei n, GLuint * samplers);
			typedef void (* PFNGLCREATEPROGRAMPIPELINES) (GLsizei n, GLuint * pipelines);
			typedef void (* PFNGLCREATEQUERIES) (GLenum target, GLsizei n, GLuint * ids);
			typedef void (* PFNGLGETQUERYBUFFEROBJECTI64V) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
			typedef void (* PFNGLGETQUERYBUFFEROBJECTIV) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
			typedef void (* PFNGLGETQUERYBUFFEROBJECTUI64V) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
			typedef void (* PFNGLGETQUERYBUFFEROBJECTUIV) (GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
			typedef void (* PFNGLMEMORYBARRIERBYREGION) (GLbitfield barriers);
			typedef void (* PFNGLGETTEXTURESUBIMAGE) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void * pixels);
			typedef void (* PFNGLGETCOMPRESSEDTEXTURESUBIMAGE) (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void * pixels);
			typedef GLenum (* PFNGLGETGRAPHICSRESETSTATUS) ();
			typedef void (* PFNGLGETNCOMPRESSEDTEXIMAGE) (GLenum target, GLint lod, GLsizei bufSize, void * pixels);
			typedef void (* PFNGLGETNTEXIMAGE) (GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * pixels);
			typedef void (* PFNGLGETNUNIFORMDV) (GLuint program, GLint location, GLsizei bufSize, GLdouble * params);
			typedef void (* PFNGLGETNUNIFORMFV) (GLuint program, GLint location, GLsizei bufSize, GLfloat * params);
			typedef void (* PFNGLGETNUNIFORMIV) (GLuint program, GLint location, GLsizei bufSize, GLint * params);
			typedef void (* PFNGLGETNUNIFORMUIV) (GLuint program, GLint location, GLsizei bufSize, GLuint * params);
			typedef void (* PFNGLREADNPIXELS) (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void * data);
			typedef void (* PFNGLGETNMAPDV) (GLenum target, GLenum query, GLsizei bufSize, GLdouble * v);
			typedef void (* PFNGLGETNMAPFV) (GLenum target, GLenum query, GLsizei bufSize, GLfloat * v);
			typedef void (* PFNGLGETNMAPIV) (GLenum target, GLenum query, GLsizei bufSize, GLint * v);
			typedef void (* PFNGLGETNPIXELMAPFV) (GLenum map, GLsizei bufSize, GLfloat * values);
			typedef void (* PFNGLGETNPIXELMAPUIV) (GLenum map, GLsizei bufSize, GLuint * values);
			typedef void (* PFNGLGETNPIXELMAPUSV) (GLenum map, GLsizei bufSize, GLushort * values);
			typedef void (* PFNGLGETNPOLYGONSTIPPLE) (GLsizei bufSize, GLubyte * pattern);
			typedef void (* PFNGLGETNCOLORTABLE) (GLenum target, GLenum format, GLenum type, GLsizei bufSize, void * table);
			typedef void (* PFNGLGETNCONVOLUTIONFILTER) (GLenum target, GLenum format, GLenum type, GLsizei bufSize, void * image);
			typedef void (* PFNGLGETNSEPARABLEFILTER) (GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void * row, GLsizei columnBufSize, void * column, void * span);
			typedef void (* PFNGLGETNHISTOGRAM) (GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void * values);
			typedef void (* PFNGLGETNMINMAX) (GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void * values);
			typedef void (* PFNGLTEXTUREBARRIER) ();
			typedef void (* PFNGLSPECIALIZESHADER) (GLuint shader, GLchar * pEntryPoint, GLuint numSpecializationConstants, GLuint * pConstantIndex, GLuint * pConstantValue);
			typedef void (* PFNGLMULTIDRAWARRAYSINDIRECTCOUNT) (GLenum mode, const void * indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
			typedef void (* PFNGLMULTIDRAWELEMENTSINDIRECTCOUNT) (GLenum mode, GLenum type, const void * indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
			typedef void (* PFNGLPOLYGONOFFSETCLAMP) (GLfloat factor, GLfloat units, GLfloat clamp);
			
			PFNGLCULLFACE pfnGlCullFace;
			PFNGLFRONTFACE pfnGlFrontFace;
			PFNGLHINT pfnGlHint;
			PFNGLLINEWIDTH pfnGlLineWidth;
			PFNGLPOINTSIZE pfnGlPointSize;
			PFNGLPOLYGONMODE pfnGlPolygonMode;
			PFNGLSCISSOR pfnGlScissor;
			PFNGLTEXPARAMETERF pfnGlTexParameterf;
			PFNGLTEXPARAMETERFV pfnGlTexParameterfv;
			PFNGLTEXPARAMETERI pfnGlTexParameteri;
			PFNGLTEXPARAMETERIV pfnGlTexParameteriv;
			PFNGLTEXIMAGE1D pfnGlTexImage1D;
			PFNGLTEXIMAGE2D pfnGlTexImage2D;
			PFNGLDRAWBUFFER pfnGlDrawBuffer;
			PFNGLCLEAR pfnGlClear;
			PFNGLCLEARCOLOR pfnGlClearColor;
			PFNGLCLEARSTENCIL pfnGlClearStencil;
			PFNGLCLEARDEPTH pfnGlClearDepth;
			PFNGLSTENCILMASK pfnGlStencilMask;
			PFNGLCOLORMASK pfnGlColorMask;
			PFNGLDEPTHMASK pfnGlDepthMask;
			PFNGLDISABLE pfnGlDisable;
			PFNGLENABLE pfnGlEnable;
			PFNGLFINISH pfnGlFinish;
			PFNGLFLUSH pfnGlFlush;
			PFNGLBLENDFUNC pfnGlBlendFunc;
			PFNGLLOGICOP pfnGlLogicOp;
			PFNGLSTENCILFUNC pfnGlStencilFunc;
			PFNGLSTENCILOP pfnGlStencilOp;
			PFNGLDEPTHFUNC pfnGlDepthFunc;
			PFNGLPIXELSTOREF pfnGlPixelStoref;
			PFNGLPIXELSTOREI pfnGlPixelStorei;
			PFNGLREADBUFFER pfnGlReadBuffer;
			PFNGLREADPIXELS pfnGlReadPixels;
			PFNGLGETBOOLEANV pfnGlGetBooleanv;
			PFNGLGETDOUBLEV pfnGlGetDoublev;
			PFNGLGETERROR pfnGlGetError;
			PFNGLGETFLOATV pfnGlGetFloatv;
			PFNGLGETINTEGERV pfnGlGetIntegerv;
			PFNGLGETSTRING pfnGlGetString;
			PFNGLGETTEXIMAGE pfnGlGetTexImage;
			PFNGLGETTEXPARAMETERFV pfnGlGetTexParameterfv;
			PFNGLGETTEXPARAMETERIV pfnGlGetTexParameteriv;
			PFNGLGETTEXLEVELPARAMETERFV pfnGlGetTexLevelParameterfv;
			PFNGLGETTEXLEVELPARAMETERIV pfnGlGetTexLevelParameteriv;
			PFNGLISENABLED pfnGlIsEnabled;
			PFNGLDEPTHRANGE pfnGlDepthRange;
			PFNGLVIEWPORT pfnGlViewport;
			PFNGLDRAWARRAYS pfnGlDrawArrays;
			PFNGLDRAWELEMENTS pfnGlDrawElements;
			PFNGLPOLYGONOFFSET pfnGlPolygonOffset;
			PFNGLCOPYTEXIMAGE1D pfnGlCopyTexImage1D;
			PFNGLCOPYTEXIMAGE2D pfnGlCopyTexImage2D;
			PFNGLCOPYTEXSUBIMAGE1D pfnGlCopyTexSubImage1D;
			PFNGLCOPYTEXSUBIMAGE2D pfnGlCopyTexSubImage2D;
			PFNGLTEXSUBIMAGE1D pfnGlTexSubImage1D;
			PFNGLTEXSUBIMAGE2D pfnGlTexSubImage2D;
			PFNGLBINDTEXTURE pfnGlBindTexture;
			PFNGLDELETETEXTURES pfnGlDeleteTextures;
			PFNGLGENTEXTURES pfnGlGenTextures;
			PFNGLISTEXTURE pfnGlIsTexture;
			PFNGLDRAWRANGEELEMENTS pfnGlDrawRangeElements;
			PFNGLTEXIMAGE3D pfnGlTexImage3D;
			PFNGLTEXSUBIMAGE3D pfnGlTexSubImage3D;
			PFNGLCOPYTEXSUBIMAGE3D pfnGlCopyTexSubImage3D;
			PFNGLACTIVETEXTURE pfnGlActiveTexture;
			PFNGLSAMPLECOVERAGE pfnGlSampleCoverage;
			PFNGLCOMPRESSEDTEXIMAGE3D pfnGlCompressedTexImage3D;
			PFNGLCOMPRESSEDTEXIMAGE2D pfnGlCompressedTexImage2D;
			PFNGLCOMPRESSEDTEXIMAGE1D pfnGlCompressedTexImage1D;
			PFNGLCOMPRESSEDTEXSUBIMAGE3D pfnGlCompressedTexSubImage3D;
			PFNGLCOMPRESSEDTEXSUBIMAGE2D pfnGlCompressedTexSubImage2D;
			PFNGLCOMPRESSEDTEXSUBIMAGE1D pfnGlCompressedTexSubImage1D;
			PFNGLGETCOMPRESSEDTEXIMAGE pfnGlGetCompressedTexImage;
			PFNGLBLENDFUNCSEPARATE pfnGlBlendFuncSeparate;
			PFNGLMULTIDRAWARRAYS pfnGlMultiDrawArrays;
			PFNGLMULTIDRAWELEMENTS pfnGlMultiDrawElements;
			PFNGLPOINTPARAMETERF pfnGlPointParameterf;
			PFNGLPOINTPARAMETERFV pfnGlPointParameterfv;
			PFNGLPOINTPARAMETERI pfnGlPointParameteri;
			PFNGLPOINTPARAMETERIV pfnGlPointParameteriv;
			PFNGLBLENDCOLOR pfnGlBlendColor;
			PFNGLBLENDEQUATION pfnGlBlendEquation;
			PFNGLGENQUERIES pfnGlGenQueries;
			PFNGLDELETEQUERIES pfnGlDeleteQueries;
			PFNGLISQUERY pfnGlIsQuery;
			PFNGLBEGINQUERY pfnGlBeginQuery;
			PFNGLENDQUERY pfnGlEndQuery;
			PFNGLGETQUERYIV pfnGlGetQueryiv;
			PFNGLGETQUERYOBJECTIV pfnGlGetQueryObjectiv;
			PFNGLGETQUERYOBJECTUIV pfnGlGetQueryObjectuiv;
			PFNGLBINDBUFFER pfnGlBindBuffer;
			PFNGLDELETEBUFFERS pfnGlDeleteBuffers;
			PFNGLGENBUFFERS pfnGlGenBuffers;
			PFNGLISBUFFER pfnGlIsBuffer;
			PFNGLBUFFERDATA pfnGlBufferData;
			PFNGLBUFFERSUBDATA pfnGlBufferSubData;
			PFNGLGETBUFFERSUBDATA pfnGlGetBufferSubData;
			PFNGLMAPBUFFER pfnGlMapBuffer;
			PFNGLUNMAPBUFFER pfnGlUnmapBuffer;
			PFNGLGETBUFFERPARAMETERIV pfnGlGetBufferParameteriv;
			PFNGLGETBUFFERPOINTERV pfnGlGetBufferPointerv;
			PFNGLBLENDEQUATIONSEPARATE pfnGlBlendEquationSeparate;
			PFNGLDRAWBUFFERS pfnGlDrawBuffers;
			PFNGLSTENCILOPSEPARATE pfnGlStencilOpSeparate;
			PFNGLSTENCILFUNCSEPARATE pfnGlStencilFuncSeparate;
			PFNGLSTENCILMASKSEPARATE pfnGlStencilMaskSeparate;
			PFNGLATTACHSHADER pfnGlAttachShader;
			PFNGLBINDATTRIBLOCATION pfnGlBindAttribLocation;
			PFNGLCOMPILESHADER pfnGlCompileShader;
			PFNGLCREATEPROGRAM pfnGlCreateProgram;
			PFNGLCREATESHADER pfnGlCreateShader;
			PFNGLDELETEPROGRAM pfnGlDeleteProgram;
			PFNGLDELETESHADER pfnGlDeleteShader;
			PFNGLDETACHSHADER pfnGlDetachShader;
			PFNGLDISABLEVERTEXATTRIBARRAY pfnGlDisableVertexAttribArray;
			PFNGLENABLEVERTEXATTRIBARRAY pfnGlEnableVertexAttribArray;
			PFNGLGETACTIVEATTRIB pfnGlGetActiveAttrib;
			PFNGLGETACTIVEUNIFORM pfnGlGetActiveUniform;
			PFNGLGETATTACHEDSHADERS pfnGlGetAttachedShaders;
			PFNGLGETATTRIBLOCATION pfnGlGetAttribLocation;
			PFNGLGETPROGRAMIV pfnGlGetProgramiv;
			PFNGLGETPROGRAMINFOLOG pfnGlGetProgramInfoLog;
			PFNGLGETSHADERIV pfnGlGetShaderiv;
			PFNGLGETSHADERINFOLOG pfnGlGetShaderInfoLog;
			PFNGLGETSHADERSOURCE pfnGlGetShaderSource;
			PFNGLGETUNIFORMLOCATION pfnGlGetUniformLocation;
			PFNGLGETUNIFORMFV pfnGlGetUniformfv;
			PFNGLGETUNIFORMIV pfnGlGetUniformiv;
			PFNGLGETVERTEXATTRIBDV pfnGlGetVertexAttribdv;
			PFNGLGETVERTEXATTRIBFV pfnGlGetVertexAttribfv;
			PFNGLGETVERTEXATTRIBIV pfnGlGetVertexAttribiv;
			PFNGLGETVERTEXATTRIBPOINTERV pfnGlGetVertexAttribPointerv;
			PFNGLISPROGRAM pfnGlIsProgram;
			PFNGLISSHADER pfnGlIsShader;
			PFNGLLINKPROGRAM pfnGlLinkProgram;
			PFNGLSHADERSOURCE pfnGlShaderSource;
			PFNGLUSEPROGRAM pfnGlUseProgram;
			PFNGLUNIFORM1F pfnGlUniform1f;
			PFNGLUNIFORM2F pfnGlUniform2f;
			PFNGLUNIFORM3F pfnGlUniform3f;
			PFNGLUNIFORM4F pfnGlUniform4f;
			PFNGLUNIFORM1I pfnGlUniform1i;
			PFNGLUNIFORM2I pfnGlUniform2i;
			PFNGLUNIFORM3I pfnGlUniform3i;
			PFNGLUNIFORM4I pfnGlUniform4i;
			PFNGLUNIFORM1FV pfnGlUniform1fv;
			PFNGLUNIFORM2FV pfnGlUniform2fv;
			PFNGLUNIFORM3FV pfnGlUniform3fv;
			PFNGLUNIFORM4FV pfnGlUniform4fv;
			PFNGLUNIFORM1IV pfnGlUniform1iv;
			PFNGLUNIFORM2IV pfnGlUniform2iv;
			PFNGLUNIFORM3IV pfnGlUniform3iv;
			PFNGLUNIFORM4IV pfnGlUniform4iv;
			PFNGLUNIFORMMATRIX2FV pfnGlUniformMatrix2fv;
			PFNGLUNIFORMMATRIX3FV pfnGlUniformMatrix3fv;
			PFNGLUNIFORMMATRIX4FV pfnGlUniformMatrix4fv;
			PFNGLVALIDATEPROGRAM pfnGlValidateProgram;
			PFNGLVERTEXATTRIB1D pfnGlVertexAttrib1d;
			PFNGLVERTEXATTRIB1DV pfnGlVertexAttrib1dv;
			PFNGLVERTEXATTRIB1F pfnGlVertexAttrib1f;
			PFNGLVERTEXATTRIB1FV pfnGlVertexAttrib1fv;
			PFNGLVERTEXATTRIB1S pfnGlVertexAttrib1s;
			PFNGLVERTEXATTRIB1SV pfnGlVertexAttrib1sv;
			PFNGLVERTEXATTRIB2D pfnGlVertexAttrib2d;
			PFNGLVERTEXATTRIB2DV pfnGlVertexAttrib2dv;
			PFNGLVERTEXATTRIB2F pfnGlVertexAttrib2f;
			PFNGLVERTEXATTRIB2FV pfnGlVertexAttrib2fv;
			PFNGLVERTEXATTRIB2S pfnGlVertexAttrib2s;
			PFNGLVERTEXATTRIB2SV pfnGlVertexAttrib2sv;
			PFNGLVERTEXATTRIB3D pfnGlVertexAttrib3d;
			PFNGLVERTEXATTRIB3DV pfnGlVertexAttrib3dv;
			PFNGLVERTEXATTRIB3F pfnGlVertexAttrib3f;
			PFNGLVERTEXATTRIB3FV pfnGlVertexAttrib3fv;
			PFNGLVERTEXATTRIB3S pfnGlVertexAttrib3s;
			PFNGLVERTEXATTRIB3SV pfnGlVertexAttrib3sv;
			PFNGLVERTEXATTRIB4NBV pfnGlVertexAttrib4Nbv;
			PFNGLVERTEXATTRIB4NIV pfnGlVertexAttrib4Niv;
			PFNGLVERTEXATTRIB4NSV pfnGlVertexAttrib4Nsv;
			PFNGLVERTEXATTRIB4NUB pfnGlVertexAttrib4Nub;
			PFNGLVERTEXATTRIB4NUBV pfnGlVertexAttrib4Nubv;
			PFNGLVERTEXATTRIB4NUIV pfnGlVertexAttrib4Nuiv;
			PFNGLVERTEXATTRIB4NUSV pfnGlVertexAttrib4Nusv;
			PFNGLVERTEXATTRIB4BV pfnGlVertexAttrib4bv;
			PFNGLVERTEXATTRIB4D pfnGlVertexAttrib4d;
			PFNGLVERTEXATTRIB4DV pfnGlVertexAttrib4dv;
			PFNGLVERTEXATTRIB4F pfnGlVertexAttrib4f;
			PFNGLVERTEXATTRIB4FV pfnGlVertexAttrib4fv;
			PFNGLVERTEXATTRIB4IV pfnGlVertexAttrib4iv;
			PFNGLVERTEXATTRIB4S pfnGlVertexAttrib4s;
			PFNGLVERTEXATTRIB4SV pfnGlVertexAttrib4sv;
			PFNGLVERTEXATTRIB4UBV pfnGlVertexAttrib4ubv;
			PFNGLVERTEXATTRIB4UIV pfnGlVertexAttrib4uiv;
			PFNGLVERTEXATTRIB4USV pfnGlVertexAttrib4usv;
			PFNGLVERTEXATTRIBPOINTER pfnGlVertexAttribPointer;
			PFNGLUNIFORMMATRIX2X3FV pfnGlUniformMatrix2x3fv;
			PFNGLUNIFORMMATRIX3X2FV pfnGlUniformMatrix3x2fv;
			PFNGLUNIFORMMATRIX2X4FV pfnGlUniformMatrix2x4fv;
			PFNGLUNIFORMMATRIX4X2FV pfnGlUniformMatrix4x2fv;
			PFNGLUNIFORMMATRIX3X4FV pfnGlUniformMatrix3x4fv;
			PFNGLUNIFORMMATRIX4X3FV pfnGlUniformMatrix4x3fv;
			PFNGLCOLORMASKI pfnGlColorMaski;
			PFNGLGETBOOLEANI_V pfnGlGetBooleani_v;
			PFNGLGETINTEGERI_V pfnGlGetIntegeri_v;
			PFNGLENABLEI pfnGlEnablei;
			PFNGLDISABLEI pfnGlDisablei;
			PFNGLISENABLEDI pfnGlIsEnabledi;
			PFNGLBEGINTRANSFORMFEEDBACK pfnGlBeginTransformFeedback;
			PFNGLENDTRANSFORMFEEDBACK pfnGlEndTransformFeedback;
			PFNGLBINDBUFFERRANGE pfnGlBindBufferRange;
			PFNGLBINDBUFFERBASE pfnGlBindBufferBase;
			PFNGLTRANSFORMFEEDBACKVARYINGS pfnGlTransformFeedbackVaryings;
			PFNGLGETTRANSFORMFEEDBACKVARYING pfnGlGetTransformFeedbackVarying;
			PFNGLCLAMPCOLOR pfnGlClampColor;
			PFNGLBEGINCONDITIONALRENDER pfnGlBeginConditionalRender;
			PFNGLENDCONDITIONALRENDER pfnGlEndConditionalRender;
			PFNGLVERTEXATTRIBIPOINTER pfnGlVertexAttribIPointer;
			PFNGLGETVERTEXATTRIBIIV pfnGlGetVertexAttribIiv;
			PFNGLGETVERTEXATTRIBIUIV pfnGlGetVertexAttribIuiv;
			PFNGLVERTEXATTRIBI1I pfnGlVertexAttribI1i;
			PFNGLVERTEXATTRIBI2I pfnGlVertexAttribI2i;
			PFNGLVERTEXATTRIBI3I pfnGlVertexAttribI3i;
			PFNGLVERTEXATTRIBI4I pfnGlVertexAttribI4i;
			PFNGLVERTEXATTRIBI1UI pfnGlVertexAttribI1ui;
			PFNGLVERTEXATTRIBI2UI pfnGlVertexAttribI2ui;
			PFNGLVERTEXATTRIBI3UI pfnGlVertexAttribI3ui;
			PFNGLVERTEXATTRIBI4UI pfnGlVertexAttribI4ui;
			PFNGLVERTEXATTRIBI1IV pfnGlVertexAttribI1iv;
			PFNGLVERTEXATTRIBI2IV pfnGlVertexAttribI2iv;
			PFNGLVERTEXATTRIBI3IV pfnGlVertexAttribI3iv;
			PFNGLVERTEXATTRIBI4IV pfnGlVertexAttribI4iv;
			PFNGLVERTEXATTRIBI1UIV pfnGlVertexAttribI1uiv;
			PFNGLVERTEXATTRIBI2UIV pfnGlVertexAttribI2uiv;
			PFNGLVERTEXATTRIBI3UIV pfnGlVertexAttribI3uiv;
			PFNGLVERTEXATTRIBI4UIV pfnGlVertexAttribI4uiv;
			PFNGLVERTEXATTRIBI4BV pfnGlVertexAttribI4bv;
			PFNGLVERTEXATTRIBI4SV pfnGlVertexAttribI4sv;
			PFNGLVERTEXATTRIBI4UBV pfnGlVertexAttribI4ubv;
			PFNGLVERTEXATTRIBI4USV pfnGlVertexAttribI4usv;
			PFNGLGETUNIFORMUIV pfnGlGetUniformuiv;
			PFNGLBINDFRAGDATALOCATION pfnGlBindFragDataLocation;
			PFNGLGETFRAGDATALOCATION pfnGlGetFragDataLocation;
			PFNGLUNIFORM1UI pfnGlUniform1ui;
			PFNGLUNIFORM2UI pfnGlUniform2ui;
			PFNGLUNIFORM3UI pfnGlUniform3ui;
			PFNGLUNIFORM4UI pfnGlUniform4ui;
			PFNGLUNIFORM1UIV pfnGlUniform1uiv;
			PFNGLUNIFORM2UIV pfnGlUniform2uiv;
			PFNGLUNIFORM3UIV pfnGlUniform3uiv;
			PFNGLUNIFORM4UIV pfnGlUniform4uiv;
			PFNGLTEXPARAMETERIIV pfnGlTexParameterIiv;
			PFNGLTEXPARAMETERIUIV pfnGlTexParameterIuiv;
			PFNGLGETTEXPARAMETERIIV pfnGlGetTexParameterIiv;
			PFNGLGETTEXPARAMETERIUIV pfnGlGetTexParameterIuiv;
			PFNGLCLEARBUFFERIV pfnGlClearBufferiv;
			PFNGLCLEARBUFFERUIV pfnGlClearBufferuiv;
			PFNGLCLEARBUFFERFV pfnGlClearBufferfv;
			PFNGLCLEARBUFFERFI pfnGlClearBufferfi;
			PFNGLGETSTRINGI pfnGlGetStringi;
			PFNGLISRENDERBUFFER pfnGlIsRenderbuffer;
			PFNGLBINDRENDERBUFFER pfnGlBindRenderbuffer;
			PFNGLDELETERENDERBUFFERS pfnGlDeleteRenderbuffers;
			PFNGLGENRENDERBUFFERS pfnGlGenRenderbuffers;
			PFNGLRENDERBUFFERSTORAGE pfnGlRenderbufferStorage;
			PFNGLGETRENDERBUFFERPARAMETERIV pfnGlGetRenderbufferParameteriv;
			PFNGLISFRAMEBUFFER pfnGlIsFramebuffer;
			PFNGLBINDFRAMEBUFFER pfnGlBindFramebuffer;
			PFNGLDELETEFRAMEBUFFERS pfnGlDeleteFramebuffers;
			PFNGLGENFRAMEBUFFERS pfnGlGenFramebuffers;
			PFNGLCHECKFRAMEBUFFERSTATUS pfnGlCheckFramebufferStatus;
			PFNGLFRAMEBUFFERTEXTURE1D pfnGlFramebufferTexture1D;
			PFNGLFRAMEBUFFERTEXTURE2D pfnGlFramebufferTexture2D;
			PFNGLFRAMEBUFFERTEXTURE3D pfnGlFramebufferTexture3D;
			PFNGLFRAMEBUFFERRENDERBUFFER pfnGlFramebufferRenderbuffer;
			PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIV pfnGlGetFramebufferAttachmentParameteriv;
			PFNGLGENERATEMIPMAP pfnGlGenerateMipmap;
			PFNGLBLITFRAMEBUFFER pfnGlBlitFramebuffer;
			PFNGLRENDERBUFFERSTORAGEMULTISAMPLE pfnGlRenderbufferStorageMultisample;
			PFNGLFRAMEBUFFERTEXTURELAYER pfnGlFramebufferTextureLayer;
			PFNGLMAPBUFFERRANGE pfnGlMapBufferRange;
			PFNGLFLUSHMAPPEDBUFFERRANGE pfnGlFlushMappedBufferRange;
			PFNGLBINDVERTEXARRAY pfnGlBindVertexArray;
			PFNGLDELETEVERTEXARRAYS pfnGlDeleteVertexArrays;
			PFNGLGENVERTEXARRAYS pfnGlGenVertexArrays;
			PFNGLISVERTEXARRAY pfnGlIsVertexArray;
			PFNGLDRAWARRAYSINSTANCED pfnGlDrawArraysInstanced;
			PFNGLDRAWELEMENTSINSTANCED pfnGlDrawElementsInstanced;
			PFNGLTEXBUFFER pfnGlTexBuffer;
			PFNGLPRIMITIVERESTARTINDEX pfnGlPrimitiveRestartIndex;
			PFNGLCOPYBUFFERSUBDATA pfnGlCopyBufferSubData;
			PFNGLGETUNIFORMINDICES pfnGlGetUniformIndices;
			PFNGLGETACTIVEUNIFORMSIV pfnGlGetActiveUniformsiv;
			PFNGLGETACTIVEUNIFORMNAME pfnGlGetActiveUniformName;
			PFNGLGETUNIFORMBLOCKINDEX pfnGlGetUniformBlockIndex;
			PFNGLGETACTIVEUNIFORMBLOCKIV pfnGlGetActiveUniformBlockiv;
			PFNGLGETACTIVEUNIFORMBLOCKNAME pfnGlGetActiveUniformBlockName;
			PFNGLUNIFORMBLOCKBINDING pfnGlUniformBlockBinding;
			PFNGLDRAWELEMENTSBASEVERTEX pfnGlDrawElementsBaseVertex;
			PFNGLDRAWRANGEELEMENTSBASEVERTEX pfnGlDrawRangeElementsBaseVertex;
			PFNGLDRAWELEMENTSINSTANCEDBASEVERTEX pfnGlDrawElementsInstancedBaseVertex;
			PFNGLMULTIDRAWELEMENTSBASEVERTEX pfnGlMultiDrawElementsBaseVertex;
			PFNGLPROVOKINGVERTEX pfnGlProvokingVertex;
			PFNGLFENCESYNC pfnGlFenceSync;
			PFNGLISSYNC pfnGlIsSync;
			PFNGLDELETESYNC pfnGlDeleteSync;
			PFNGLCLIENTWAITSYNC pfnGlClientWaitSync;
			PFNGLWAITSYNC pfnGlWaitSync;
			PFNGLGETINTEGER64V pfnGlGetInteger64v;
			PFNGLGETSYNCIV pfnGlGetSynciv;
			PFNGLGETINTEGER64I_V pfnGlGetInteger64i_v;
			PFNGLGETBUFFERPARAMETERI64V pfnGlGetBufferParameteri64v;
			PFNGLFRAMEBUFFERTEXTURE pfnGlFramebufferTexture;
			PFNGLTEXIMAGE2DMULTISAMPLE pfnGlTexImage2DMultisample;
			PFNGLTEXIMAGE3DMULTISAMPLE pfnGlTexImage3DMultisample;
			PFNGLGETMULTISAMPLEFV pfnGlGetMultisamplefv;
			PFNGLSAMPLEMASKI pfnGlSampleMaski;
			PFNGLBINDFRAGDATALOCATIONINDEXED pfnGlBindFragDataLocationIndexed;
			PFNGLGETFRAGDATAINDEX pfnGlGetFragDataIndex;
			PFNGLGENSAMPLERS pfnGlGenSamplers;
			PFNGLDELETESAMPLERS pfnGlDeleteSamplers;
			PFNGLISSAMPLER pfnGlIsSampler;
			PFNGLBINDSAMPLER pfnGlBindSampler;
			PFNGLSAMPLERPARAMETERI pfnGlSamplerParameteri;
			PFNGLSAMPLERPARAMETERIV pfnGlSamplerParameteriv;
			PFNGLSAMPLERPARAMETERF pfnGlSamplerParameterf;
			PFNGLSAMPLERPARAMETERFV pfnGlSamplerParameterfv;
			PFNGLSAMPLERPARAMETERIIV pfnGlSamplerParameterIiv;
			PFNGLSAMPLERPARAMETERIUIV pfnGlSamplerParameterIuiv;
			PFNGLGETSAMPLERPARAMETERIV pfnGlGetSamplerParameteriv;
			PFNGLGETSAMPLERPARAMETERIIV pfnGlGetSamplerParameterIiv;
			PFNGLGETSAMPLERPARAMETERFV pfnGlGetSamplerParameterfv;
			PFNGLGETSAMPLERPARAMETERIUIV pfnGlGetSamplerParameterIuiv;
			PFNGLQUERYCOUNTER pfnGlQueryCounter;
			PFNGLGETQUERYOBJECTI64V pfnGlGetQueryObjecti64v;
			PFNGLGETQUERYOBJECTUI64V pfnGlGetQueryObjectui64v;
			PFNGLVERTEXATTRIBDIVISOR pfnGlVertexAttribDivisor;
			PFNGLVERTEXATTRIBP1UI pfnGlVertexAttribP1ui;
			PFNGLVERTEXATTRIBP1UIV pfnGlVertexAttribP1uiv;
			PFNGLVERTEXATTRIBP2UI pfnGlVertexAttribP2ui;
			PFNGLVERTEXATTRIBP2UIV pfnGlVertexAttribP2uiv;
			PFNGLVERTEXATTRIBP3UI pfnGlVertexAttribP3ui;
			PFNGLVERTEXATTRIBP3UIV pfnGlVertexAttribP3uiv;
			PFNGLVERTEXATTRIBP4UI pfnGlVertexAttribP4ui;
			PFNGLVERTEXATTRIBP4UIV pfnGlVertexAttribP4uiv;
			PFNGLVERTEXP2UI pfnGlVertexP2ui;
			PFNGLVERTEXP2UIV pfnGlVertexP2uiv;
			PFNGLVERTEXP3UI pfnGlVertexP3ui;
			PFNGLVERTEXP3UIV pfnGlVertexP3uiv;
			PFNGLVERTEXP4UI pfnGlVertexP4ui;
			PFNGLVERTEXP4UIV pfnGlVertexP4uiv;
			PFNGLTEXCOORDP1UI pfnGlTexCoordP1ui;
			PFNGLTEXCOORDP1UIV pfnGlTexCoordP1uiv;
			PFNGLTEXCOORDP2UI pfnGlTexCoordP2ui;
			PFNGLTEXCOORDP2UIV pfnGlTexCoordP2uiv;
			PFNGLTEXCOORDP3UI pfnGlTexCoordP3ui;
			PFNGLTEXCOORDP3UIV pfnGlTexCoordP3uiv;
			PFNGLTEXCOORDP4UI pfnGlTexCoordP4ui;
			PFNGLTEXCOORDP4UIV pfnGlTexCoordP4uiv;
			PFNGLMULTITEXCOORDP1UI pfnGlMultiTexCoordP1ui;
			PFNGLMULTITEXCOORDP1UIV pfnGlMultiTexCoordP1uiv;
			PFNGLMULTITEXCOORDP2UI pfnGlMultiTexCoordP2ui;
			PFNGLMULTITEXCOORDP2UIV pfnGlMultiTexCoordP2uiv;
			PFNGLMULTITEXCOORDP3UI pfnGlMultiTexCoordP3ui;
			PFNGLMULTITEXCOORDP3UIV pfnGlMultiTexCoordP3uiv;
			PFNGLMULTITEXCOORDP4UI pfnGlMultiTexCoordP4ui;
			PFNGLMULTITEXCOORDP4UIV pfnGlMultiTexCoordP4uiv;
			PFNGLNORMALP3UI pfnGlNormalP3ui;
			PFNGLNORMALP3UIV pfnGlNormalP3uiv;
			PFNGLCOLORP3UI pfnGlColorP3ui;
			PFNGLCOLORP3UIV pfnGlColorP3uiv;
			PFNGLCOLORP4UI pfnGlColorP4ui;
			PFNGLCOLORP4UIV pfnGlColorP4uiv;
			PFNGLSECONDARYCOLORP3UI pfnGlSecondaryColorP3ui;
			PFNGLSECONDARYCOLORP3UIV pfnGlSecondaryColorP3uiv;
			PFNGLMINSAMPLESHADING pfnGlMinSampleShading;
			PFNGLBLENDEQUATIONI pfnGlBlendEquationi;
			PFNGLBLENDEQUATIONSEPARATEI pfnGlBlendEquationSeparatei;
			PFNGLBLENDFUNCI pfnGlBlendFunci;
			PFNGLBLENDFUNCSEPARATEI pfnGlBlendFuncSeparatei;
			PFNGLDRAWARRAYSINDIRECT pfnGlDrawArraysIndirect;
			PFNGLDRAWELEMENTSINDIRECT pfnGlDrawElementsIndirect;
			PFNGLUNIFORM1D pfnGlUniform1d;
			PFNGLUNIFORM2D pfnGlUniform2d;
			PFNGLUNIFORM3D pfnGlUniform3d;
			PFNGLUNIFORM4D pfnGlUniform4d;
			PFNGLUNIFORM1DV pfnGlUniform1dv;
			PFNGLUNIFORM2DV pfnGlUniform2dv;
			PFNGLUNIFORM3DV pfnGlUniform3dv;
			PFNGLUNIFORM4DV pfnGlUniform4dv;
			PFNGLUNIFORMMATRIX2DV pfnGlUniformMatrix2dv;
			PFNGLUNIFORMMATRIX3DV pfnGlUniformMatrix3dv;
			PFNGLUNIFORMMATRIX4DV pfnGlUniformMatrix4dv;
			PFNGLUNIFORMMATRIX2X3DV pfnGlUniformMatrix2x3dv;
			PFNGLUNIFORMMATRIX2X4DV pfnGlUniformMatrix2x4dv;
			PFNGLUNIFORMMATRIX3X2DV pfnGlUniformMatrix3x2dv;
			PFNGLUNIFORMMATRIX3X4DV pfnGlUniformMatrix3x4dv;
			PFNGLUNIFORMMATRIX4X2DV pfnGlUniformMatrix4x2dv;
			PFNGLUNIFORMMATRIX4X3DV pfnGlUniformMatrix4x3dv;
			PFNGLGETUNIFORMDV pfnGlGetUniformdv;
			PFNGLGETSUBROUTINEUNIFORMLOCATION pfnGlGetSubroutineUniformLocation;
			PFNGLGETSUBROUTINEINDEX pfnGlGetSubroutineIndex;
			PFNGLGETACTIVESUBROUTINEUNIFORMIV pfnGlGetActiveSubroutineUniformiv;
			PFNGLGETACTIVESUBROUTINEUNIFORMNAME pfnGlGetActiveSubroutineUniformName;
			PFNGLGETACTIVESUBROUTINENAME pfnGlGetActiveSubroutineName;
			PFNGLUNIFORMSUBROUTINESUIV pfnGlUniformSubroutinesuiv;
			PFNGLGETUNIFORMSUBROUTINEUIV pfnGlGetUniformSubroutineuiv;
			PFNGLGETPROGRAMSTAGEIV pfnGlGetProgramStageiv;
			PFNGLPATCHPARAMETERI pfnGlPatchParameteri;
			PFNGLPATCHPARAMETERFV pfnGlPatchParameterfv;
			PFNGLBINDTRANSFORMFEEDBACK pfnGlBindTransformFeedback;
			PFNGLDELETETRANSFORMFEEDBACKS pfnGlDeleteTransformFeedbacks;
			PFNGLGENTRANSFORMFEEDBACKS pfnGlGenTransformFeedbacks;
			PFNGLISTRANSFORMFEEDBACK pfnGlIsTransformFeedback;
			PFNGLPAUSETRANSFORMFEEDBACK pfnGlPauseTransformFeedback;
			PFNGLRESUMETRANSFORMFEEDBACK pfnGlResumeTransformFeedback;
			PFNGLDRAWTRANSFORMFEEDBACK pfnGlDrawTransformFeedback;
			PFNGLDRAWTRANSFORMFEEDBACKSTREAM pfnGlDrawTransformFeedbackStream;
			PFNGLBEGINQUERYINDEXED pfnGlBeginQueryIndexed;
			PFNGLENDQUERYINDEXED pfnGlEndQueryIndexed;
			PFNGLGETQUERYINDEXEDIV pfnGlGetQueryIndexediv;
			PFNGLRELEASESHADERCOMPILER pfnGlReleaseShaderCompiler;
			PFNGLSHADERBINARY pfnGlShaderBinary;
			PFNGLGETSHADERPRECISIONFORMAT pfnGlGetShaderPrecisionFormat;
			PFNGLDEPTHRANGEF pfnGlDepthRangef;
			PFNGLCLEARDEPTHF pfnGlClearDepthf;
			PFNGLGETPROGRAMBINARY pfnGlGetProgramBinary;
			PFNGLPROGRAMBINARY pfnGlProgramBinary;
			PFNGLPROGRAMPARAMETERI pfnGlProgramParameteri;
			PFNGLUSEPROGRAMSTAGES pfnGlUseProgramStages;
			PFNGLACTIVESHADERPROGRAM pfnGlActiveShaderProgram;
			PFNGLCREATESHADERPROGRAMV pfnGlCreateShaderProgramv;
			PFNGLBINDPROGRAMPIPELINE pfnGlBindProgramPipeline;
			PFNGLDELETEPROGRAMPIPELINES pfnGlDeleteProgramPipelines;
			PFNGLGENPROGRAMPIPELINES pfnGlGenProgramPipelines;
			PFNGLISPROGRAMPIPELINE pfnGlIsProgramPipeline;
			PFNGLGETPROGRAMPIPELINEIV pfnGlGetProgramPipelineiv;
			PFNGLPROGRAMUNIFORM1I pfnGlProgramUniform1i;
			PFNGLPROGRAMUNIFORM1IV pfnGlProgramUniform1iv;
			PFNGLPROGRAMUNIFORM1F pfnGlProgramUniform1f;
			PFNGLPROGRAMUNIFORM1FV pfnGlProgramUniform1fv;
			PFNGLPROGRAMUNIFORM1D pfnGlProgramUniform1d;
			PFNGLPROGRAMUNIFORM1DV pfnGlProgramUniform1dv;
			PFNGLPROGRAMUNIFORM1UI pfnGlProgramUniform1ui;
			PFNGLPROGRAMUNIFORM1UIV pfnGlProgramUniform1uiv;
			PFNGLPROGRAMUNIFORM2I pfnGlProgramUniform2i;
			PFNGLPROGRAMUNIFORM2IV pfnGlProgramUniform2iv;
			PFNGLPROGRAMUNIFORM2F pfnGlProgramUniform2f;
			PFNGLPROGRAMUNIFORM2FV pfnGlProgramUniform2fv;
			PFNGLPROGRAMUNIFORM2D pfnGlProgramUniform2d;
			PFNGLPROGRAMUNIFORM2DV pfnGlProgramUniform2dv;
			PFNGLPROGRAMUNIFORM2UI pfnGlProgramUniform2ui;
			PFNGLPROGRAMUNIFORM2UIV pfnGlProgramUniform2uiv;
			PFNGLPROGRAMUNIFORM3I pfnGlProgramUniform3i;
			PFNGLPROGRAMUNIFORM3IV pfnGlProgramUniform3iv;
			PFNGLPROGRAMUNIFORM3F pfnGlProgramUniform3f;
			PFNGLPROGRAMUNIFORM3FV pfnGlProgramUniform3fv;
			PFNGLPROGRAMUNIFORM3D pfnGlProgramUniform3d;
			PFNGLPROGRAMUNIFORM3DV pfnGlProgramUniform3dv;
			PFNGLPROGRAMUNIFORM3UI pfnGlProgramUniform3ui;
			PFNGLPROGRAMUNIFORM3UIV pfnGlProgramUniform3uiv;
			PFNGLPROGRAMUNIFORM4I pfnGlProgramUniform4i;
			PFNGLPROGRAMUNIFORM4IV pfnGlProgramUniform4iv;
			PFNGLPROGRAMUNIFORM4F pfnGlProgramUniform4f;
			PFNGLPROGRAMUNIFORM4FV pfnGlProgramUniform4fv;
			PFNGLPROGRAMUNIFORM4D pfnGlProgramUniform4d;
			PFNGLPROGRAMUNIFORM4DV pfnGlProgramUniform4dv;
			PFNGLPROGRAMUNIFORM4UI pfnGlProgramUniform4ui;
			PFNGLPROGRAMUNIFORM4UIV pfnGlProgramUniform4uiv;
			PFNGLPROGRAMUNIFORMMATRIX2FV pfnGlProgramUniformMatrix2fv;
			PFNGLPROGRAMUNIFORMMATRIX3FV pfnGlProgramUniformMatrix3fv;
			PFNGLPROGRAMUNIFORMMATRIX4FV pfnGlProgramUniformMatrix4fv;
			PFNGLPROGRAMUNIFORMMATRIX2DV pfnGlProgramUniformMatrix2dv;
			PFNGLPROGRAMUNIFORMMATRIX3DV pfnGlProgramUniformMatrix3dv;
			PFNGLPROGRAMUNIFORMMATRIX4DV pfnGlProgramUniformMatrix4dv;
			PFNGLPROGRAMUNIFORMMATRIX2X3FV pfnGlProgramUniformMatrix2x3fv;
			PFNGLPROGRAMUNIFORMMATRIX3X2FV pfnGlProgramUniformMatrix3x2fv;
			PFNGLPROGRAMUNIFORMMATRIX2X4FV pfnGlProgramUniformMatrix2x4fv;
			PFNGLPROGRAMUNIFORMMATRIX4X2FV pfnGlProgramUniformMatrix4x2fv;
			PFNGLPROGRAMUNIFORMMATRIX3X4FV pfnGlProgramUniformMatrix3x4fv;
			PFNGLPROGRAMUNIFORMMATRIX4X3FV pfnGlProgramUniformMatrix4x3fv;
			PFNGLPROGRAMUNIFORMMATRIX2X3DV pfnGlProgramUniformMatrix2x3dv;
			PFNGLPROGRAMUNIFORMMATRIX3X2DV pfnGlProgramUniformMatrix3x2dv;
			PFNGLPROGRAMUNIFORMMATRIX2X4DV pfnGlProgramUniformMatrix2x4dv;
			PFNGLPROGRAMUNIFORMMATRIX4X2DV pfnGlProgramUniformMatrix4x2dv;
			PFNGLPROGRAMUNIFORMMATRIX3X4DV pfnGlProgramUniformMatrix3x4dv;
			PFNGLPROGRAMUNIFORMMATRIX4X3DV pfnGlProgramUniformMatrix4x3dv;
			PFNGLVALIDATEPROGRAMPIPELINE pfnGlValidateProgramPipeline;
			PFNGLGETPROGRAMPIPELINEINFOLOG pfnGlGetProgramPipelineInfoLog;
			PFNGLVERTEXATTRIBL1D pfnGlVertexAttribL1d;
			PFNGLVERTEXATTRIBL2D pfnGlVertexAttribL2d;
			PFNGLVERTEXATTRIBL3D pfnGlVertexAttribL3d;
			PFNGLVERTEXATTRIBL4D pfnGlVertexAttribL4d;
			PFNGLVERTEXATTRIBL1DV pfnGlVertexAttribL1dv;
			PFNGLVERTEXATTRIBL2DV pfnGlVertexAttribL2dv;
			PFNGLVERTEXATTRIBL3DV pfnGlVertexAttribL3dv;
			PFNGLVERTEXATTRIBL4DV pfnGlVertexAttribL4dv;
			PFNGLVERTEXATTRIBLPOINTER pfnGlVertexAttribLPointer;
			PFNGLGETVERTEXATTRIBLDV pfnGlGetVertexAttribLdv;
			PFNGLVIEWPORTARRAYV pfnGlViewportArrayv;
			PFNGLVIEWPORTINDEXEDF pfnGlViewportIndexedf;
			PFNGLVIEWPORTINDEXEDFV pfnGlViewportIndexedfv;
			PFNGLSCISSORARRAYV pfnGlScissorArrayv;
			PFNGLSCISSORINDEXED pfnGlScissorIndexed;
			PFNGLSCISSORINDEXEDV pfnGlScissorIndexedv;
			PFNGLDEPTHRANGEARRAYV pfnGlDepthRangeArrayv;
			PFNGLDEPTHRANGEINDEXED pfnGlDepthRangeIndexed;
			PFNGLGETFLOATI_V pfnGlGetFloati_v;
			PFNGLGETDOUBLEI_V pfnGlGetDoublei_v;
			PFNGLDRAWARRAYSINSTANCEDBASEINSTANCE pfnGlDrawArraysInstancedBaseInstance;
			PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCE pfnGlDrawElementsInstancedBaseInstance;
			PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCE pfnGlDrawElementsInstancedBaseVertexBaseInstance;
			PFNGLGETINTERNALFORMATIV pfnGlGetInternalformativ;
			PFNGLGETACTIVEATOMICCOUNTERBUFFERIV pfnGlGetActiveAtomicCounterBufferiv;
			PFNGLBINDIMAGETEXTURE pfnGlBindImageTexture;
			PFNGLMEMORYBARRIER pfnGlMemoryBarrier;
			PFNGLTEXSTORAGE1D pfnGlTexStorage1D;
			PFNGLTEXSTORAGE2D pfnGlTexStorage2D;
			PFNGLTEXSTORAGE3D pfnGlTexStorage3D;
			PFNGLDRAWTRANSFORMFEEDBACKINSTANCED pfnGlDrawTransformFeedbackInstanced;
			PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCED pfnGlDrawTransformFeedbackStreamInstanced;
			PFNGLCLEARBUFFERDATA pfnGlClearBufferData;
			PFNGLCLEARBUFFERSUBDATA pfnGlClearBufferSubData;
			PFNGLDISPATCHCOMPUTE pfnGlDispatchCompute;
			PFNGLDISPATCHCOMPUTEINDIRECT pfnGlDispatchComputeIndirect;
			PFNGLCOPYIMAGESUBDATA pfnGlCopyImageSubData;
			PFNGLFRAMEBUFFERPARAMETERI pfnGlFramebufferParameteri;
			PFNGLGETFRAMEBUFFERPARAMETERIV pfnGlGetFramebufferParameteriv;
			PFNGLGETINTERNALFORMATI64V pfnGlGetInternalformati64v;
			PFNGLINVALIDATETEXSUBIMAGE pfnGlInvalidateTexSubImage;
			PFNGLINVALIDATETEXIMAGE pfnGlInvalidateTexImage;
			PFNGLINVALIDATEBUFFERSUBDATA pfnGlInvalidateBufferSubData;
			PFNGLINVALIDATEBUFFERDATA pfnGlInvalidateBufferData;
			PFNGLINVALIDATEFRAMEBUFFER pfnGlInvalidateFramebuffer;
			PFNGLINVALIDATESUBFRAMEBUFFER pfnGlInvalidateSubFramebuffer;
			PFNGLMULTIDRAWARRAYSINDIRECT pfnGlMultiDrawArraysIndirect;
			PFNGLMULTIDRAWELEMENTSINDIRECT pfnGlMultiDrawElementsIndirect;
			PFNGLGETPROGRAMINTERFACEIV pfnGlGetProgramInterfaceiv;
			PFNGLGETPROGRAMRESOURCEINDEX pfnGlGetProgramResourceIndex;
			PFNGLGETPROGRAMRESOURCENAME pfnGlGetProgramResourceName;
			PFNGLGETPROGRAMRESOURCEIV pfnGlGetProgramResourceiv;
			PFNGLGETPROGRAMRESOURCELOCATION pfnGlGetProgramResourceLocation;
			PFNGLGETPROGRAMRESOURCELOCATIONINDEX pfnGlGetProgramResourceLocationIndex;
			PFNGLSHADERSTORAGEBLOCKBINDING pfnGlShaderStorageBlockBinding;
			PFNGLTEXBUFFERRANGE pfnGlTexBufferRange;
			PFNGLTEXSTORAGE2DMULTISAMPLE pfnGlTexStorage2DMultisample;
			PFNGLTEXSTORAGE3DMULTISAMPLE pfnGlTexStorage3DMultisample;
			PFNGLTEXTUREVIEW pfnGlTextureView;
			PFNGLBINDVERTEXBUFFER pfnGlBindVertexBuffer;
			PFNGLVERTEXATTRIBFORMAT pfnGlVertexAttribFormat;
			PFNGLVERTEXATTRIBIFORMAT pfnGlVertexAttribIFormat;
			PFNGLVERTEXATTRIBLFORMAT pfnGlVertexAttribLFormat;
			PFNGLVERTEXATTRIBBINDING pfnGlVertexAttribBinding;
			PFNGLVERTEXBINDINGDIVISOR pfnGlVertexBindingDivisor;
			PFNGLDEBUGMESSAGECONTROL pfnGlDebugMessageControl;
			PFNGLDEBUGMESSAGEINSERT pfnGlDebugMessageInsert;
			PFNGLDEBUGMESSAGECALLBACK pfnGlDebugMessageCallback;
			PFNGLGETDEBUGMESSAGELOG pfnGlGetDebugMessageLog;
			PFNGLPUSHDEBUGGROUP pfnGlPushDebugGroup;
			PFNGLPOPDEBUGGROUP pfnGlPopDebugGroup;
			PFNGLOBJECTLABEL pfnGlObjectLabel;
			PFNGLGETOBJECTLABEL pfnGlGetObjectLabel;
			PFNGLOBJECTPTRLABEL pfnGlObjectPtrLabel;
			PFNGLGETOBJECTPTRLABEL pfnGlGetObjectPtrLabel;
			PFNGLGETPOINTERV pfnGlGetPointerv;
			PFNGLBUFFERSTORAGE pfnGlBufferStorage;
			PFNGLCLEARTEXIMAGE pfnGlClearTexImage;
			PFNGLCLEARTEXSUBIMAGE pfnGlClearTexSubImage;
			PFNGLBINDBUFFERSBASE pfnGlBindBuffersBase;
			PFNGLBINDBUFFERSRANGE pfnGlBindBuffersRange;
			PFNGLBINDTEXTURES pfnGlBindTextures;
			PFNGLBINDSAMPLERS pfnGlBindSamplers;
			PFNGLBINDIMAGETEXTURES pfnGlBindImageTextures;
			PFNGLBINDVERTEXBUFFERS pfnGlBindVertexBuffers;
			PFNGLCLIPCONTROL pfnGlClipControl;
			PFNGLCREATETRANSFORMFEEDBACKS pfnGlCreateTransformFeedbacks;
			PFNGLTRANSFORMFEEDBACKBUFFERBASE pfnGlTransformFeedbackBufferBase;
			PFNGLTRANSFORMFEEDBACKBUFFERRANGE pfnGlTransformFeedbackBufferRange;
			PFNGLGETTRANSFORMFEEDBACKIV pfnGlGetTransformFeedbackiv;
			PFNGLGETTRANSFORMFEEDBACKI_V pfnGlGetTransformFeedbacki_v;
			PFNGLGETTRANSFORMFEEDBACKI64_V pfnGlGetTransformFeedbacki64_v;
			PFNGLCREATEBUFFERS pfnGlCreateBuffers;
			PFNGLNAMEDBUFFERSTORAGE pfnGlNamedBufferStorage;
			PFNGLNAMEDBUFFERDATA pfnGlNamedBufferData;
			PFNGLNAMEDBUFFERSUBDATA pfnGlNamedBufferSubData;
			PFNGLCOPYNAMEDBUFFERSUBDATA pfnGlCopyNamedBufferSubData;
			PFNGLCLEARNAMEDBUFFERDATA pfnGlClearNamedBufferData;
			PFNGLCLEARNAMEDBUFFERSUBDATA pfnGlClearNamedBufferSubData;
			PFNGLMAPNAMEDBUFFER pfnGlMapNamedBuffer;
			PFNGLMAPNAMEDBUFFERRANGE pfnGlMapNamedBufferRange;
			PFNGLUNMAPNAMEDBUFFER pfnGlUnmapNamedBuffer;
			PFNGLFLUSHMAPPEDNAMEDBUFFERRANGE pfnGlFlushMappedNamedBufferRange;
			PFNGLGETNAMEDBUFFERPARAMETERIV pfnGlGetNamedBufferParameteriv;
			PFNGLGETNAMEDBUFFERPARAMETERI64V pfnGlGetNamedBufferParameteri64v;
			PFNGLGETNAMEDBUFFERPOINTERV pfnGlGetNamedBufferPointerv;
			PFNGLGETNAMEDBUFFERSUBDATA pfnGlGetNamedBufferSubData;
			PFNGLCREATEFRAMEBUFFERS pfnGlCreateFramebuffers;
			PFNGLNAMEDFRAMEBUFFERRENDERBUFFER pfnGlNamedFramebufferRenderbuffer;
			PFNGLNAMEDFRAMEBUFFERPARAMETERI pfnGlNamedFramebufferParameteri;
			PFNGLNAMEDFRAMEBUFFERTEXTURE pfnGlNamedFramebufferTexture;
			PFNGLNAMEDFRAMEBUFFERTEXTURELAYER pfnGlNamedFramebufferTextureLayer;
			PFNGLNAMEDFRAMEBUFFERDRAWBUFFER pfnGlNamedFramebufferDrawBuffer;
			PFNGLNAMEDFRAMEBUFFERDRAWBUFFERS pfnGlNamedFramebufferDrawBuffers;
			PFNGLNAMEDFRAMEBUFFERREADBUFFER pfnGlNamedFramebufferReadBuffer;
			PFNGLINVALIDATENAMEDFRAMEBUFFERDATA pfnGlInvalidateNamedFramebufferData;
			PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATA pfnGlInvalidateNamedFramebufferSubData;
			PFNGLCLEARNAMEDFRAMEBUFFERIV pfnGlClearNamedFramebufferiv;
			PFNGLCLEARNAMEDFRAMEBUFFERUIV pfnGlClearNamedFramebufferuiv;
			PFNGLCLEARNAMEDFRAMEBUFFERFV pfnGlClearNamedFramebufferfv;
			PFNGLCLEARNAMEDFRAMEBUFFERFI pfnGlClearNamedFramebufferfi;
			PFNGLBLITNAMEDFRAMEBUFFER pfnGlBlitNamedFramebuffer;
			PFNGLCHECKNAMEDFRAMEBUFFERSTATUS pfnGlCheckNamedFramebufferStatus;
			PFNGLGETNAMEDFRAMEBUFFERPARAMETERIV pfnGlGetNamedFramebufferParameteriv;
			PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIV pfnGlGetNamedFramebufferAttachmentParameteriv;
			PFNGLCREATERENDERBUFFERS pfnGlCreateRenderbuffers;
			PFNGLNAMEDRENDERBUFFERSTORAGE pfnGlNamedRenderbufferStorage;
			PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLE pfnGlNamedRenderbufferStorageMultisample;
			PFNGLGETNAMEDRENDERBUFFERPARAMETERIV pfnGlGetNamedRenderbufferParameteriv;
			PFNGLCREATETEXTURES pfnGlCreateTextures;
			PFNGLTEXTUREBUFFER pfnGlTextureBuffer;
			PFNGLTEXTUREBUFFERRANGE pfnGlTextureBufferRange;
			PFNGLTEXTURESTORAGE1D pfnGlTextureStorage1D;
			PFNGLTEXTURESTORAGE2D pfnGlTextureStorage2D;
			PFNGLTEXTURESTORAGE3D pfnGlTextureStorage3D;
			PFNGLTEXTURESTORAGE2DMULTISAMPLE pfnGlTextureStorage2DMultisample;
			PFNGLTEXTURESTORAGE3DMULTISAMPLE pfnGlTextureStorage3DMultisample;
			PFNGLTEXTURESUBIMAGE1D pfnGlTextureSubImage1D;
			PFNGLTEXTURESUBIMAGE2D pfnGlTextureSubImage2D;
			PFNGLTEXTURESUBIMAGE3D pfnGlTextureSubImage3D;
			PFNGLCOMPRESSEDTEXTURESUBIMAGE1D pfnGlCompressedTextureSubImage1D;
			PFNGLCOMPRESSEDTEXTURESUBIMAGE2D pfnGlCompressedTextureSubImage2D;
			PFNGLCOMPRESSEDTEXTURESUBIMAGE3D pfnGlCompressedTextureSubImage3D;
			PFNGLCOPYTEXTURESUBIMAGE1D pfnGlCopyTextureSubImage1D;
			PFNGLCOPYTEXTURESUBIMAGE2D pfnGlCopyTextureSubImage2D;
			PFNGLCOPYTEXTURESUBIMAGE3D pfnGlCopyTextureSubImage3D;
			PFNGLTEXTUREPARAMETERF pfnGlTextureParameterf;
			PFNGLTEXTUREPARAMETERFV pfnGlTextureParameterfv;
			PFNGLTEXTUREPARAMETERI pfnGlTextureParameteri;
			PFNGLTEXTUREPARAMETERIIV pfnGlTextureParameterIiv;
			PFNGLTEXTUREPARAMETERIUIV pfnGlTextureParameterIuiv;
			PFNGLTEXTUREPARAMETERIV pfnGlTextureParameteriv;
			PFNGLGENERATETEXTUREMIPMAP pfnGlGenerateTextureMipmap;
			PFNGLBINDTEXTUREUNIT pfnGlBindTextureUnit;
			PFNGLGETTEXTUREIMAGE pfnGlGetTextureImage;
			PFNGLGETCOMPRESSEDTEXTUREIMAGE pfnGlGetCompressedTextureImage;
			PFNGLGETTEXTURELEVELPARAMETERFV pfnGlGetTextureLevelParameterfv;
			PFNGLGETTEXTURELEVELPARAMETERIV pfnGlGetTextureLevelParameteriv;
			PFNGLGETTEXTUREPARAMETERFV pfnGlGetTextureParameterfv;
			PFNGLGETTEXTUREPARAMETERIIV pfnGlGetTextureParameterIiv;
			PFNGLGETTEXTUREPARAMETERIUIV pfnGlGetTextureParameterIuiv;
			PFNGLGETTEXTUREPARAMETERIV pfnGlGetTextureParameteriv;
			PFNGLCREATEVERTEXARRAYS pfnGlCreateVertexArrays;
			PFNGLDISABLEVERTEXARRAYATTRIB pfnGlDisableVertexArrayAttrib;
			PFNGLENABLEVERTEXARRAYATTRIB pfnGlEnableVertexArrayAttrib;
			PFNGLVERTEXARRAYELEMENTBUFFER pfnGlVertexArrayElementBuffer;
			PFNGLVERTEXARRAYVERTEXBUFFER pfnGlVertexArrayVertexBuffer;
			PFNGLVERTEXARRAYVERTEXBUFFERS pfnGlVertexArrayVertexBuffers;
			PFNGLVERTEXARRAYATTRIBBINDING pfnGlVertexArrayAttribBinding;
			PFNGLVERTEXARRAYATTRIBFORMAT pfnGlVertexArrayAttribFormat;
			PFNGLVERTEXARRAYATTRIBIFORMAT pfnGlVertexArrayAttribIFormat;
			PFNGLVERTEXARRAYATTRIBLFORMAT pfnGlVertexArrayAttribLFormat;
			PFNGLVERTEXARRAYBINDINGDIVISOR pfnGlVertexArrayBindingDivisor;
			PFNGLGETVERTEXARRAYIV pfnGlGetVertexArrayiv;
			PFNGLGETVERTEXARRAYINDEXEDIV pfnGlGetVertexArrayIndexediv;
			PFNGLGETVERTEXARRAYINDEXED64IV pfnGlGetVertexArrayIndexed64iv;
			PFNGLCREATESAMPLERS pfnGlCreateSamplers;
			PFNGLCREATEPROGRAMPIPELINES pfnGlCreateProgramPipelines;
			PFNGLCREATEQUERIES pfnGlCreateQueries;
			PFNGLGETQUERYBUFFEROBJECTI64V pfnGlGetQueryBufferObjecti64v;
			PFNGLGETQUERYBUFFEROBJECTIV pfnGlGetQueryBufferObjectiv;
			PFNGLGETQUERYBUFFEROBJECTUI64V pfnGlGetQueryBufferObjectui64v;
			PFNGLGETQUERYBUFFEROBJECTUIV pfnGlGetQueryBufferObjectuiv;
			PFNGLMEMORYBARRIERBYREGION pfnGlMemoryBarrierByRegion;
			PFNGLGETTEXTURESUBIMAGE pfnGlGetTextureSubImage;
			PFNGLGETCOMPRESSEDTEXTURESUBIMAGE pfnGlGetCompressedTextureSubImage;
			PFNGLGETGRAPHICSRESETSTATUS pfnGlGetGraphicsResetStatus;
			PFNGLGETNCOMPRESSEDTEXIMAGE pfnGlGetnCompressedTexImage;
			PFNGLGETNTEXIMAGE pfnGlGetnTexImage;
			PFNGLGETNUNIFORMDV pfnGlGetnUniformdv;
			PFNGLGETNUNIFORMFV pfnGlGetnUniformfv;
			PFNGLGETNUNIFORMIV pfnGlGetnUniformiv;
			PFNGLGETNUNIFORMUIV pfnGlGetnUniformuiv;
			PFNGLREADNPIXELS pfnGlReadnPixels;
			PFNGLGETNMAPDV pfnGlGetnMapdv;
			PFNGLGETNMAPFV pfnGlGetnMapfv;
			PFNGLGETNMAPIV pfnGlGetnMapiv;
			PFNGLGETNPIXELMAPFV pfnGlGetnPixelMapfv;
			PFNGLGETNPIXELMAPUIV pfnGlGetnPixelMapuiv;
			PFNGLGETNPIXELMAPUSV pfnGlGetnPixelMapusv;
			PFNGLGETNPOLYGONSTIPPLE pfnGlGetnPolygonStipple;
			PFNGLGETNCOLORTABLE pfnGlGetnColorTable;
			PFNGLGETNCONVOLUTIONFILTER pfnGlGetnConvolutionFilter;
			PFNGLGETNSEPARABLEFILTER pfnGlGetnSeparableFilter;
			PFNGLGETNHISTOGRAM pfnGlGetnHistogram;
			PFNGLGETNMINMAX pfnGlGetnMinmax;
			PFNGLTEXTUREBARRIER pfnGlTextureBarrier;
			PFNGLSPECIALIZESHADER pfnGlSpecializeShader;
			PFNGLMULTIDRAWARRAYSINDIRECTCOUNT pfnGlMultiDrawArraysIndirectCount;
			PFNGLMULTIDRAWELEMENTSINDIRECTCOUNT pfnGlMultiDrawElementsIndirectCount;
			PFNGLPOLYGONOFFSETCLAMP pfnGlPolygonOffsetClamp;
			
			void Initialize(LookupFunctionPointer lookupFunctionPointer) {
				pfnGlCullFace = (PFNGLCULLFACE)lookupFunctionPointer("glCullFace");
				pfnGlFrontFace = (PFNGLFRONTFACE)lookupFunctionPointer("glFrontFace");
				pfnGlHint = (PFNGLHINT)lookupFunctionPointer("glHint");
				pfnGlLineWidth = (PFNGLLINEWIDTH)lookupFunctionPointer("glLineWidth");
				pfnGlPointSize = (PFNGLPOINTSIZE)lookupFunctionPointer("glPointSize");
				pfnGlPolygonMode = (PFNGLPOLYGONMODE)lookupFunctionPointer("glPolygonMode");
				pfnGlScissor = (PFNGLSCISSOR)lookupFunctionPointer("glScissor");
				pfnGlTexParameterf = (PFNGLTEXPARAMETERF)lookupFunctionPointer("glTexParameterf");
				pfnGlTexParameterfv = (PFNGLTEXPARAMETERFV)lookupFunctionPointer("glTexParameterfv");
				pfnGlTexParameteri = (PFNGLTEXPARAMETERI)lookupFunctionPointer("glTexParameteri");
				pfnGlTexParameteriv = (PFNGLTEXPARAMETERIV)lookupFunctionPointer("glTexParameteriv");
				pfnGlTexImage1D = (PFNGLTEXIMAGE1D)lookupFunctionPointer("glTexImage1D");
				pfnGlTexImage2D = (PFNGLTEXIMAGE2D)lookupFunctionPointer("glTexImage2D");
				pfnGlDrawBuffer = (PFNGLDRAWBUFFER)lookupFunctionPointer("glDrawBuffer");
				pfnGlClear = (PFNGLCLEAR)lookupFunctionPointer("glClear");
				pfnGlClearColor = (PFNGLCLEARCOLOR)lookupFunctionPointer("glClearColor");
				pfnGlClearStencil = (PFNGLCLEARSTENCIL)lookupFunctionPointer("glClearStencil");
				pfnGlClearDepth = (PFNGLCLEARDEPTH)lookupFunctionPointer("glClearDepth");
				pfnGlStencilMask = (PFNGLSTENCILMASK)lookupFunctionPointer("glStencilMask");
				pfnGlColorMask = (PFNGLCOLORMASK)lookupFunctionPointer("glColorMask");
				pfnGlDepthMask = (PFNGLDEPTHMASK)lookupFunctionPointer("glDepthMask");
				pfnGlDisable = (PFNGLDISABLE)lookupFunctionPointer("glDisable");
				pfnGlEnable = (PFNGLENABLE)lookupFunctionPointer("glEnable");
				pfnGlFinish = (PFNGLFINISH)lookupFunctionPointer("glFinish");
				pfnGlFlush = (PFNGLFLUSH)lookupFunctionPointer("glFlush");
				pfnGlBlendFunc = (PFNGLBLENDFUNC)lookupFunctionPointer("glBlendFunc");
				pfnGlLogicOp = (PFNGLLOGICOP)lookupFunctionPointer("glLogicOp");
				pfnGlStencilFunc = (PFNGLSTENCILFUNC)lookupFunctionPointer("glStencilFunc");
				pfnGlStencilOp = (PFNGLSTENCILOP)lookupFunctionPointer("glStencilOp");
				pfnGlDepthFunc = (PFNGLDEPTHFUNC)lookupFunctionPointer("glDepthFunc");
				pfnGlPixelStoref = (PFNGLPIXELSTOREF)lookupFunctionPointer("glPixelStoref");
				pfnGlPixelStorei = (PFNGLPIXELSTOREI)lookupFunctionPointer("glPixelStorei");
				pfnGlReadBuffer = (PFNGLREADBUFFER)lookupFunctionPointer("glReadBuffer");
				pfnGlReadPixels = (PFNGLREADPIXELS)lookupFunctionPointer("glReadPixels");
				pfnGlGetBooleanv = (PFNGLGETBOOLEANV)lookupFunctionPointer("glGetBooleanv");
				pfnGlGetDoublev = (PFNGLGETDOUBLEV)lookupFunctionPointer("glGetDoublev");
				pfnGlGetError = (PFNGLGETERROR)lookupFunctionPointer("glGetError");
				pfnGlGetFloatv = (PFNGLGETFLOATV)lookupFunctionPointer("glGetFloatv");
				pfnGlGetIntegerv = (PFNGLGETINTEGERV)lookupFunctionPointer("glGetIntegerv");
				pfnGlGetString = (PFNGLGETSTRING)lookupFunctionPointer("glGetString");
				pfnGlGetTexImage = (PFNGLGETTEXIMAGE)lookupFunctionPointer("glGetTexImage");
				pfnGlGetTexParameterfv = (PFNGLGETTEXPARAMETERFV)lookupFunctionPointer("glGetTexParameterfv");
				pfnGlGetTexParameteriv = (PFNGLGETTEXPARAMETERIV)lookupFunctionPointer("glGetTexParameteriv");
				pfnGlGetTexLevelParameterfv = (PFNGLGETTEXLEVELPARAMETERFV)lookupFunctionPointer("glGetTexLevelParameterfv");
				pfnGlGetTexLevelParameteriv = (PFNGLGETTEXLEVELPARAMETERIV)lookupFunctionPointer("glGetTexLevelParameteriv");
				pfnGlIsEnabled = (PFNGLISENABLED)lookupFunctionPointer("glIsEnabled");
				pfnGlDepthRange = (PFNGLDEPTHRANGE)lookupFunctionPointer("glDepthRange");
				pfnGlViewport = (PFNGLVIEWPORT)lookupFunctionPointer("glViewport");
				pfnGlDrawArrays = (PFNGLDRAWARRAYS)lookupFunctionPointer("glDrawArrays");
				pfnGlDrawElements = (PFNGLDRAWELEMENTS)lookupFunctionPointer("glDrawElements");
				pfnGlPolygonOffset = (PFNGLPOLYGONOFFSET)lookupFunctionPointer("glPolygonOffset");
				pfnGlCopyTexImage1D = (PFNGLCOPYTEXIMAGE1D)lookupFunctionPointer("glCopyTexImage1D");
				pfnGlCopyTexImage2D = (PFNGLCOPYTEXIMAGE2D)lookupFunctionPointer("glCopyTexImage2D");
				pfnGlCopyTexSubImage1D = (PFNGLCOPYTEXSUBIMAGE1D)lookupFunctionPointer("glCopyTexSubImage1D");
				pfnGlCopyTexSubImage2D = (PFNGLCOPYTEXSUBIMAGE2D)lookupFunctionPointer("glCopyTexSubImage2D");
				pfnGlTexSubImage1D = (PFNGLTEXSUBIMAGE1D)lookupFunctionPointer("glTexSubImage1D");
				pfnGlTexSubImage2D = (PFNGLTEXSUBIMAGE2D)lookupFunctionPointer("glTexSubImage2D");
				pfnGlBindTexture = (PFNGLBINDTEXTURE)lookupFunctionPointer("glBindTexture");
				pfnGlDeleteTextures = (PFNGLDELETETEXTURES)lookupFunctionPointer("glDeleteTextures");
				pfnGlGenTextures = (PFNGLGENTEXTURES)lookupFunctionPointer("glGenTextures");
				pfnGlIsTexture = (PFNGLISTEXTURE)lookupFunctionPointer("glIsTexture");
				pfnGlDrawRangeElements = (PFNGLDRAWRANGEELEMENTS)lookupFunctionPointer("glDrawRangeElements");
				pfnGlTexImage3D = (PFNGLTEXIMAGE3D)lookupFunctionPointer("glTexImage3D");
				pfnGlTexSubImage3D = (PFNGLTEXSUBIMAGE3D)lookupFunctionPointer("glTexSubImage3D");
				pfnGlCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3D)lookupFunctionPointer("glCopyTexSubImage3D");
				pfnGlActiveTexture = (PFNGLACTIVETEXTURE)lookupFunctionPointer("glActiveTexture");
				pfnGlSampleCoverage = (PFNGLSAMPLECOVERAGE)lookupFunctionPointer("glSampleCoverage");
				pfnGlCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3D)lookupFunctionPointer("glCompressedTexImage3D");
				pfnGlCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2D)lookupFunctionPointer("glCompressedTexImage2D");
				pfnGlCompressedTexImage1D = (PFNGLCOMPRESSEDTEXIMAGE1D)lookupFunctionPointer("glCompressedTexImage1D");
				pfnGlCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3D)lookupFunctionPointer("glCompressedTexSubImage3D");
				pfnGlCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2D)lookupFunctionPointer("glCompressedTexSubImage2D");
				pfnGlCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1D)lookupFunctionPointer("glCompressedTexSubImage1D");
				pfnGlGetCompressedTexImage = (PFNGLGETCOMPRESSEDTEXIMAGE)lookupFunctionPointer("glGetCompressedTexImage");
				pfnGlBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATE)lookupFunctionPointer("glBlendFuncSeparate");
				pfnGlMultiDrawArrays = (PFNGLMULTIDRAWARRAYS)lookupFunctionPointer("glMultiDrawArrays");
				pfnGlMultiDrawElements = (PFNGLMULTIDRAWELEMENTS)lookupFunctionPointer("glMultiDrawElements");
				pfnGlPointParameterf = (PFNGLPOINTPARAMETERF)lookupFunctionPointer("glPointParameterf");
				pfnGlPointParameterfv = (PFNGLPOINTPARAMETERFV)lookupFunctionPointer("glPointParameterfv");
				pfnGlPointParameteri = (PFNGLPOINTPARAMETERI)lookupFunctionPointer("glPointParameteri");
				pfnGlPointParameteriv = (PFNGLPOINTPARAMETERIV)lookupFunctionPointer("glPointParameteriv");
				pfnGlBlendColor = (PFNGLBLENDCOLOR)lookupFunctionPointer("glBlendColor");
				pfnGlBlendEquation = (PFNGLBLENDEQUATION)lookupFunctionPointer("glBlendEquation");
				pfnGlGenQueries = (PFNGLGENQUERIES)lookupFunctionPointer("glGenQueries");
				pfnGlDeleteQueries = (PFNGLDELETEQUERIES)lookupFunctionPointer("glDeleteQueries");
				pfnGlIsQuery = (PFNGLISQUERY)lookupFunctionPointer("glIsQuery");
				pfnGlBeginQuery = (PFNGLBEGINQUERY)lookupFunctionPointer("glBeginQuery");
				pfnGlEndQuery = (PFNGLENDQUERY)lookupFunctionPointer("glEndQuery");
				pfnGlGetQueryiv = (PFNGLGETQUERYIV)lookupFunctionPointer("glGetQueryiv");
				pfnGlGetQueryObjectiv = (PFNGLGETQUERYOBJECTIV)lookupFunctionPointer("glGetQueryObjectiv");
				pfnGlGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIV)lookupFunctionPointer("glGetQueryObjectuiv");
				pfnGlBindBuffer = (PFNGLBINDBUFFER)lookupFunctionPointer("glBindBuffer");
				pfnGlDeleteBuffers = (PFNGLDELETEBUFFERS)lookupFunctionPointer("glDeleteBuffers");
				pfnGlGenBuffers = (PFNGLGENBUFFERS)lookupFunctionPointer("glGenBuffers");
				pfnGlIsBuffer = (PFNGLISBUFFER)lookupFunctionPointer("glIsBuffer");
				pfnGlBufferData = (PFNGLBUFFERDATA)lookupFunctionPointer("glBufferData");
				pfnGlBufferSubData = (PFNGLBUFFERSUBDATA)lookupFunctionPointer("glBufferSubData");
				pfnGlGetBufferSubData = (PFNGLGETBUFFERSUBDATA)lookupFunctionPointer("glGetBufferSubData");
				pfnGlMapBuffer = (PFNGLMAPBUFFER)lookupFunctionPointer("glMapBuffer");
				pfnGlUnmapBuffer = (PFNGLUNMAPBUFFER)lookupFunctionPointer("glUnmapBuffer");
				pfnGlGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIV)lookupFunctionPointer("glGetBufferParameteriv");
				pfnGlGetBufferPointerv = (PFNGLGETBUFFERPOINTERV)lookupFunctionPointer("glGetBufferPointerv");
				pfnGlBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATE)lookupFunctionPointer("glBlendEquationSeparate");
				pfnGlDrawBuffers = (PFNGLDRAWBUFFERS)lookupFunctionPointer("glDrawBuffers");
				pfnGlStencilOpSeparate = (PFNGLSTENCILOPSEPARATE)lookupFunctionPointer("glStencilOpSeparate");
				pfnGlStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATE)lookupFunctionPointer("glStencilFuncSeparate");
				pfnGlStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATE)lookupFunctionPointer("glStencilMaskSeparate");
				pfnGlAttachShader = (PFNGLATTACHSHADER)lookupFunctionPointer("glAttachShader");
				pfnGlBindAttribLocation = (PFNGLBINDATTRIBLOCATION)lookupFunctionPointer("glBindAttribLocation");
				pfnGlCompileShader = (PFNGLCOMPILESHADER)lookupFunctionPointer("glCompileShader");
				pfnGlCreateProgram = (PFNGLCREATEPROGRAM)lookupFunctionPointer("glCreateProgram");
				pfnGlCreateShader = (PFNGLCREATESHADER)lookupFunctionPointer("glCreateShader");
				pfnGlDeleteProgram = (PFNGLDELETEPROGRAM)lookupFunctionPointer("glDeleteProgram");
				pfnGlDeleteShader = (PFNGLDELETESHADER)lookupFunctionPointer("glDeleteShader");
				pfnGlDetachShader = (PFNGLDETACHSHADER)lookupFunctionPointer("glDetachShader");
				pfnGlDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAY)lookupFunctionPointer("glDisableVertexAttribArray");
				pfnGlEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAY)lookupFunctionPointer("glEnableVertexAttribArray");
				pfnGlGetActiveAttrib = (PFNGLGETACTIVEATTRIB)lookupFunctionPointer("glGetActiveAttrib");
				pfnGlGetActiveUniform = (PFNGLGETACTIVEUNIFORM)lookupFunctionPointer("glGetActiveUniform");
				pfnGlGetAttachedShaders = (PFNGLGETATTACHEDSHADERS)lookupFunctionPointer("glGetAttachedShaders");
				pfnGlGetAttribLocation = (PFNGLGETATTRIBLOCATION)lookupFunctionPointer("glGetAttribLocation");
				pfnGlGetProgramiv = (PFNGLGETPROGRAMIV)lookupFunctionPointer("glGetProgramiv");
				pfnGlGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOG)lookupFunctionPointer("glGetProgramInfoLog");
				pfnGlGetShaderiv = (PFNGLGETSHADERIV)lookupFunctionPointer("glGetShaderiv");
				pfnGlGetShaderInfoLog = (PFNGLGETSHADERINFOLOG)lookupFunctionPointer("glGetShaderInfoLog");
				pfnGlGetShaderSource = (PFNGLGETSHADERSOURCE)lookupFunctionPointer("glGetShaderSource");
				pfnGlGetUniformLocation = (PFNGLGETUNIFORMLOCATION)lookupFunctionPointer("glGetUniformLocation");
				pfnGlGetUniformfv = (PFNGLGETUNIFORMFV)lookupFunctionPointer("glGetUniformfv");
				pfnGlGetUniformiv = (PFNGLGETUNIFORMIV)lookupFunctionPointer("glGetUniformiv");
				pfnGlGetVertexAttribdv = (PFNGLGETVERTEXATTRIBDV)lookupFunctionPointer("glGetVertexAttribdv");
				pfnGlGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFV)lookupFunctionPointer("glGetVertexAttribfv");
				pfnGlGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIV)lookupFunctionPointer("glGetVertexAttribiv");
				pfnGlGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERV)lookupFunctionPointer("glGetVertexAttribPointerv");
				pfnGlIsProgram = (PFNGLISPROGRAM)lookupFunctionPointer("glIsProgram");
				pfnGlIsShader = (PFNGLISSHADER)lookupFunctionPointer("glIsShader");
				pfnGlLinkProgram = (PFNGLLINKPROGRAM)lookupFunctionPointer("glLinkProgram");
				pfnGlShaderSource = (PFNGLSHADERSOURCE)lookupFunctionPointer("glShaderSource");
				pfnGlUseProgram = (PFNGLUSEPROGRAM)lookupFunctionPointer("glUseProgram");
				pfnGlUniform1f = (PFNGLUNIFORM1F)lookupFunctionPointer("glUniform1f");
				pfnGlUniform2f = (PFNGLUNIFORM2F)lookupFunctionPointer("glUniform2f");
				pfnGlUniform3f = (PFNGLUNIFORM3F)lookupFunctionPointer("glUniform3f");
				pfnGlUniform4f = (PFNGLUNIFORM4F)lookupFunctionPointer("glUniform4f");
				pfnGlUniform1i = (PFNGLUNIFORM1I)lookupFunctionPointer("glUniform1i");
				pfnGlUniform2i = (PFNGLUNIFORM2I)lookupFunctionPointer("glUniform2i");
				pfnGlUniform3i = (PFNGLUNIFORM3I)lookupFunctionPointer("glUniform3i");
				pfnGlUniform4i = (PFNGLUNIFORM4I)lookupFunctionPointer("glUniform4i");
				pfnGlUniform1fv = (PFNGLUNIFORM1FV)lookupFunctionPointer("glUniform1fv");
				pfnGlUniform2fv = (PFNGLUNIFORM2FV)lookupFunctionPointer("glUniform2fv");
				pfnGlUniform3fv = (PFNGLUNIFORM3FV)lookupFunctionPointer("glUniform3fv");
				pfnGlUniform4fv = (PFNGLUNIFORM4FV)lookupFunctionPointer("glUniform4fv");
				pfnGlUniform1iv = (PFNGLUNIFORM1IV)lookupFunctionPointer("glUniform1iv");
				pfnGlUniform2iv = (PFNGLUNIFORM2IV)lookupFunctionPointer("glUniform2iv");
				pfnGlUniform3iv = (PFNGLUNIFORM3IV)lookupFunctionPointer("glUniform3iv");
				pfnGlUniform4iv = (PFNGLUNIFORM4IV)lookupFunctionPointer("glUniform4iv");
				pfnGlUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FV)lookupFunctionPointer("glUniformMatrix2fv");
				pfnGlUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FV)lookupFunctionPointer("glUniformMatrix3fv");
				pfnGlUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FV)lookupFunctionPointer("glUniformMatrix4fv");
				pfnGlValidateProgram = (PFNGLVALIDATEPROGRAM)lookupFunctionPointer("glValidateProgram");
				pfnGlVertexAttrib1d = (PFNGLVERTEXATTRIB1D)lookupFunctionPointer("glVertexAttrib1d");
				pfnGlVertexAttrib1dv = (PFNGLVERTEXATTRIB1DV)lookupFunctionPointer("glVertexAttrib1dv");
				pfnGlVertexAttrib1f = (PFNGLVERTEXATTRIB1F)lookupFunctionPointer("glVertexAttrib1f");
				pfnGlVertexAttrib1fv = (PFNGLVERTEXATTRIB1FV)lookupFunctionPointer("glVertexAttrib1fv");
				pfnGlVertexAttrib1s = (PFNGLVERTEXATTRIB1S)lookupFunctionPointer("glVertexAttrib1s");
				pfnGlVertexAttrib1sv = (PFNGLVERTEXATTRIB1SV)lookupFunctionPointer("glVertexAttrib1sv");
				pfnGlVertexAttrib2d = (PFNGLVERTEXATTRIB2D)lookupFunctionPointer("glVertexAttrib2d");
				pfnGlVertexAttrib2dv = (PFNGLVERTEXATTRIB2DV)lookupFunctionPointer("glVertexAttrib2dv");
				pfnGlVertexAttrib2f = (PFNGLVERTEXATTRIB2F)lookupFunctionPointer("glVertexAttrib2f");
				pfnGlVertexAttrib2fv = (PFNGLVERTEXATTRIB2FV)lookupFunctionPointer("glVertexAttrib2fv");
				pfnGlVertexAttrib2s = (PFNGLVERTEXATTRIB2S)lookupFunctionPointer("glVertexAttrib2s");
				pfnGlVertexAttrib2sv = (PFNGLVERTEXATTRIB2SV)lookupFunctionPointer("glVertexAttrib2sv");
				pfnGlVertexAttrib3d = (PFNGLVERTEXATTRIB3D)lookupFunctionPointer("glVertexAttrib3d");
				pfnGlVertexAttrib3dv = (PFNGLVERTEXATTRIB3DV)lookupFunctionPointer("glVertexAttrib3dv");
				pfnGlVertexAttrib3f = (PFNGLVERTEXATTRIB3F)lookupFunctionPointer("glVertexAttrib3f");
				pfnGlVertexAttrib3fv = (PFNGLVERTEXATTRIB3FV)lookupFunctionPointer("glVertexAttrib3fv");
				pfnGlVertexAttrib3s = (PFNGLVERTEXATTRIB3S)lookupFunctionPointer("glVertexAttrib3s");
				pfnGlVertexAttrib3sv = (PFNGLVERTEXATTRIB3SV)lookupFunctionPointer("glVertexAttrib3sv");
				pfnGlVertexAttrib4Nbv = (PFNGLVERTEXATTRIB4NBV)lookupFunctionPointer("glVertexAttrib4Nbv");
				pfnGlVertexAttrib4Niv = (PFNGLVERTEXATTRIB4NIV)lookupFunctionPointer("glVertexAttrib4Niv");
				pfnGlVertexAttrib4Nsv = (PFNGLVERTEXATTRIB4NSV)lookupFunctionPointer("glVertexAttrib4Nsv");
				pfnGlVertexAttrib4Nub = (PFNGLVERTEXATTRIB4NUB)lookupFunctionPointer("glVertexAttrib4Nub");
				pfnGlVertexAttrib4Nubv = (PFNGLVERTEXATTRIB4NUBV)lookupFunctionPointer("glVertexAttrib4Nubv");
				pfnGlVertexAttrib4Nuiv = (PFNGLVERTEXATTRIB4NUIV)lookupFunctionPointer("glVertexAttrib4Nuiv");
				pfnGlVertexAttrib4Nusv = (PFNGLVERTEXATTRIB4NUSV)lookupFunctionPointer("glVertexAttrib4Nusv");
				pfnGlVertexAttrib4bv = (PFNGLVERTEXATTRIB4BV)lookupFunctionPointer("glVertexAttrib4bv");
				pfnGlVertexAttrib4d = (PFNGLVERTEXATTRIB4D)lookupFunctionPointer("glVertexAttrib4d");
				pfnGlVertexAttrib4dv = (PFNGLVERTEXATTRIB4DV)lookupFunctionPointer("glVertexAttrib4dv");
				pfnGlVertexAttrib4f = (PFNGLVERTEXATTRIB4F)lookupFunctionPointer("glVertexAttrib4f");
				pfnGlVertexAttrib4fv = (PFNGLVERTEXATTRIB4FV)lookupFunctionPointer("glVertexAttrib4fv");
				pfnGlVertexAttrib4iv = (PFNGLVERTEXATTRIB4IV)lookupFunctionPointer("glVertexAttrib4iv");
				pfnGlVertexAttrib4s = (PFNGLVERTEXATTRIB4S)lookupFunctionPointer("glVertexAttrib4s");
				pfnGlVertexAttrib4sv = (PFNGLVERTEXATTRIB4SV)lookupFunctionPointer("glVertexAttrib4sv");
				pfnGlVertexAttrib4ubv = (PFNGLVERTEXATTRIB4UBV)lookupFunctionPointer("glVertexAttrib4ubv");
				pfnGlVertexAttrib4uiv = (PFNGLVERTEXATTRIB4UIV)lookupFunctionPointer("glVertexAttrib4uiv");
				pfnGlVertexAttrib4usv = (PFNGLVERTEXATTRIB4USV)lookupFunctionPointer("glVertexAttrib4usv");
				pfnGlVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTER)lookupFunctionPointer("glVertexAttribPointer");
				pfnGlUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FV)lookupFunctionPointer("glUniformMatrix2x3fv");
				pfnGlUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FV)lookupFunctionPointer("glUniformMatrix3x2fv");
				pfnGlUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FV)lookupFunctionPointer("glUniformMatrix2x4fv");
				pfnGlUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FV)lookupFunctionPointer("glUniformMatrix4x2fv");
				pfnGlUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FV)lookupFunctionPointer("glUniformMatrix3x4fv");
				pfnGlUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FV)lookupFunctionPointer("glUniformMatrix4x3fv");
				pfnGlColorMaski = (PFNGLCOLORMASKI)lookupFunctionPointer("glColorMaski");
				pfnGlGetBooleani_v = (PFNGLGETBOOLEANI_V)lookupFunctionPointer("glGetBooleani_v");
				pfnGlGetIntegeri_v = (PFNGLGETINTEGERI_V)lookupFunctionPointer("glGetIntegeri_v");
				pfnGlEnablei = (PFNGLENABLEI)lookupFunctionPointer("glEnablei");
				pfnGlDisablei = (PFNGLDISABLEI)lookupFunctionPointer("glDisablei");
				pfnGlIsEnabledi = (PFNGLISENABLEDI)lookupFunctionPointer("glIsEnabledi");
				pfnGlBeginTransformFeedback = (PFNGLBEGINTRANSFORMFEEDBACK)lookupFunctionPointer("glBeginTransformFeedback");
				pfnGlEndTransformFeedback = (PFNGLENDTRANSFORMFEEDBACK)lookupFunctionPointer("glEndTransformFeedback");
				pfnGlBindBufferRange = (PFNGLBINDBUFFERRANGE)lookupFunctionPointer("glBindBufferRange");
				pfnGlBindBufferBase = (PFNGLBINDBUFFERBASE)lookupFunctionPointer("glBindBufferBase");
				pfnGlTransformFeedbackVaryings = (PFNGLTRANSFORMFEEDBACKVARYINGS)lookupFunctionPointer("glTransformFeedbackVaryings");
				pfnGlGetTransformFeedbackVarying = (PFNGLGETTRANSFORMFEEDBACKVARYING)lookupFunctionPointer("glGetTransformFeedbackVarying");
				pfnGlClampColor = (PFNGLCLAMPCOLOR)lookupFunctionPointer("glClampColor");
				pfnGlBeginConditionalRender = (PFNGLBEGINCONDITIONALRENDER)lookupFunctionPointer("glBeginConditionalRender");
				pfnGlEndConditionalRender = (PFNGLENDCONDITIONALRENDER)lookupFunctionPointer("glEndConditionalRender");
				pfnGlVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTER)lookupFunctionPointer("glVertexAttribIPointer");
				pfnGlGetVertexAttribIiv = (PFNGLGETVERTEXATTRIBIIV)lookupFunctionPointer("glGetVertexAttribIiv");
				pfnGlGetVertexAttribIuiv = (PFNGLGETVERTEXATTRIBIUIV)lookupFunctionPointer("glGetVertexAttribIuiv");
				pfnGlVertexAttribI1i = (PFNGLVERTEXATTRIBI1I)lookupFunctionPointer("glVertexAttribI1i");
				pfnGlVertexAttribI2i = (PFNGLVERTEXATTRIBI2I)lookupFunctionPointer("glVertexAttribI2i");
				pfnGlVertexAttribI3i = (PFNGLVERTEXATTRIBI3I)lookupFunctionPointer("glVertexAttribI3i");
				pfnGlVertexAttribI4i = (PFNGLVERTEXATTRIBI4I)lookupFunctionPointer("glVertexAttribI4i");
				pfnGlVertexAttribI1ui = (PFNGLVERTEXATTRIBI1UI)lookupFunctionPointer("glVertexAttribI1ui");
				pfnGlVertexAttribI2ui = (PFNGLVERTEXATTRIBI2UI)lookupFunctionPointer("glVertexAttribI2ui");
				pfnGlVertexAttribI3ui = (PFNGLVERTEXATTRIBI3UI)lookupFunctionPointer("glVertexAttribI3ui");
				pfnGlVertexAttribI4ui = (PFNGLVERTEXATTRIBI4UI)lookupFunctionPointer("glVertexAttribI4ui");
				pfnGlVertexAttribI1iv = (PFNGLVERTEXATTRIBI1IV)lookupFunctionPointer("glVertexAttribI1iv");
				pfnGlVertexAttribI2iv = (PFNGLVERTEXATTRIBI2IV)lookupFunctionPointer("glVertexAttribI2iv");
				pfnGlVertexAttribI3iv = (PFNGLVERTEXATTRIBI3IV)lookupFunctionPointer("glVertexAttribI3iv");
				pfnGlVertexAttribI4iv = (PFNGLVERTEXATTRIBI4IV)lookupFunctionPointer("glVertexAttribI4iv");
				pfnGlVertexAttribI1uiv = (PFNGLVERTEXATTRIBI1UIV)lookupFunctionPointer("glVertexAttribI1uiv");
				pfnGlVertexAttribI2uiv = (PFNGLVERTEXATTRIBI2UIV)lookupFunctionPointer("glVertexAttribI2uiv");
				pfnGlVertexAttribI3uiv = (PFNGLVERTEXATTRIBI3UIV)lookupFunctionPointer("glVertexAttribI3uiv");
				pfnGlVertexAttribI4uiv = (PFNGLVERTEXATTRIBI4UIV)lookupFunctionPointer("glVertexAttribI4uiv");
				pfnGlVertexAttribI4bv = (PFNGLVERTEXATTRIBI4BV)lookupFunctionPointer("glVertexAttribI4bv");
				pfnGlVertexAttribI4sv = (PFNGLVERTEXATTRIBI4SV)lookupFunctionPointer("glVertexAttribI4sv");
				pfnGlVertexAttribI4ubv = (PFNGLVERTEXATTRIBI4UBV)lookupFunctionPointer("glVertexAttribI4ubv");
				pfnGlVertexAttribI4usv = (PFNGLVERTEXATTRIBI4USV)lookupFunctionPointer("glVertexAttribI4usv");
				pfnGlGetUniformuiv = (PFNGLGETUNIFORMUIV)lookupFunctionPointer("glGetUniformuiv");
				pfnGlBindFragDataLocation = (PFNGLBINDFRAGDATALOCATION)lookupFunctionPointer("glBindFragDataLocation");
				pfnGlGetFragDataLocation = (PFNGLGETFRAGDATALOCATION)lookupFunctionPointer("glGetFragDataLocation");
				pfnGlUniform1ui = (PFNGLUNIFORM1UI)lookupFunctionPointer("glUniform1ui");
				pfnGlUniform2ui = (PFNGLUNIFORM2UI)lookupFunctionPointer("glUniform2ui");
				pfnGlUniform3ui = (PFNGLUNIFORM3UI)lookupFunctionPointer("glUniform3ui");
				pfnGlUniform4ui = (PFNGLUNIFORM4UI)lookupFunctionPointer("glUniform4ui");
				pfnGlUniform1uiv = (PFNGLUNIFORM1UIV)lookupFunctionPointer("glUniform1uiv");
				pfnGlUniform2uiv = (PFNGLUNIFORM2UIV)lookupFunctionPointer("glUniform2uiv");
				pfnGlUniform3uiv = (PFNGLUNIFORM3UIV)lookupFunctionPointer("glUniform3uiv");
				pfnGlUniform4uiv = (PFNGLUNIFORM4UIV)lookupFunctionPointer("glUniform4uiv");
				pfnGlTexParameterIiv = (PFNGLTEXPARAMETERIIV)lookupFunctionPointer("glTexParameterIiv");
				pfnGlTexParameterIuiv = (PFNGLTEXPARAMETERIUIV)lookupFunctionPointer("glTexParameterIuiv");
				pfnGlGetTexParameterIiv = (PFNGLGETTEXPARAMETERIIV)lookupFunctionPointer("glGetTexParameterIiv");
				pfnGlGetTexParameterIuiv = (PFNGLGETTEXPARAMETERIUIV)lookupFunctionPointer("glGetTexParameterIuiv");
				pfnGlClearBufferiv = (PFNGLCLEARBUFFERIV)lookupFunctionPointer("glClearBufferiv");
				pfnGlClearBufferuiv = (PFNGLCLEARBUFFERUIV)lookupFunctionPointer("glClearBufferuiv");
				pfnGlClearBufferfv = (PFNGLCLEARBUFFERFV)lookupFunctionPointer("glClearBufferfv");
				pfnGlClearBufferfi = (PFNGLCLEARBUFFERFI)lookupFunctionPointer("glClearBufferfi");
				pfnGlGetStringi = (PFNGLGETSTRINGI)lookupFunctionPointer("glGetStringi");
				pfnGlIsRenderbuffer = (PFNGLISRENDERBUFFER)lookupFunctionPointer("glIsRenderbuffer");
				pfnGlBindRenderbuffer = (PFNGLBINDRENDERBUFFER)lookupFunctionPointer("glBindRenderbuffer");
				pfnGlDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERS)lookupFunctionPointer("glDeleteRenderbuffers");
				pfnGlGenRenderbuffers = (PFNGLGENRENDERBUFFERS)lookupFunctionPointer("glGenRenderbuffers");
				pfnGlRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGE)lookupFunctionPointer("glRenderbufferStorage");
				pfnGlGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIV)lookupFunctionPointer("glGetRenderbufferParameteriv");
				pfnGlIsFramebuffer = (PFNGLISFRAMEBUFFER)lookupFunctionPointer("glIsFramebuffer");
				pfnGlBindFramebuffer = (PFNGLBINDFRAMEBUFFER)lookupFunctionPointer("glBindFramebuffer");
				pfnGlDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERS)lookupFunctionPointer("glDeleteFramebuffers");
				pfnGlGenFramebuffers = (PFNGLGENFRAMEBUFFERS)lookupFunctionPointer("glGenFramebuffers");
				pfnGlCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUS)lookupFunctionPointer("glCheckFramebufferStatus");
				pfnGlFramebufferTexture1D = (PFNGLFRAMEBUFFERTEXTURE1D)lookupFunctionPointer("glFramebufferTexture1D");
				pfnGlFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2D)lookupFunctionPointer("glFramebufferTexture2D");
				pfnGlFramebufferTexture3D = (PFNGLFRAMEBUFFERTEXTURE3D)lookupFunctionPointer("glFramebufferTexture3D");
				pfnGlFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFER)lookupFunctionPointer("glFramebufferRenderbuffer");
				pfnGlGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIV)lookupFunctionPointer("glGetFramebufferAttachmentParameteriv");
				pfnGlGenerateMipmap = (PFNGLGENERATEMIPMAP)lookupFunctionPointer("glGenerateMipmap");
				pfnGlBlitFramebuffer = (PFNGLBLITFRAMEBUFFER)lookupFunctionPointer("glBlitFramebuffer");
				pfnGlRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLE)lookupFunctionPointer("glRenderbufferStorageMultisample");
				pfnGlFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYER)lookupFunctionPointer("glFramebufferTextureLayer");
				pfnGlMapBufferRange = (PFNGLMAPBUFFERRANGE)lookupFunctionPointer("glMapBufferRange");
				pfnGlFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGE)lookupFunctionPointer("glFlushMappedBufferRange");
				pfnGlBindVertexArray = (PFNGLBINDVERTEXARRAY)lookupFunctionPointer("glBindVertexArray");
				pfnGlDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYS)lookupFunctionPointer("glDeleteVertexArrays");
				pfnGlGenVertexArrays = (PFNGLGENVERTEXARRAYS)lookupFunctionPointer("glGenVertexArrays");
				pfnGlIsVertexArray = (PFNGLISVERTEXARRAY)lookupFunctionPointer("glIsVertexArray");
				pfnGlDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCED)lookupFunctionPointer("glDrawArraysInstanced");
				pfnGlDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCED)lookupFunctionPointer("glDrawElementsInstanced");
				pfnGlTexBuffer = (PFNGLTEXBUFFER)lookupFunctionPointer("glTexBuffer");
				pfnGlPrimitiveRestartIndex = (PFNGLPRIMITIVERESTARTINDEX)lookupFunctionPointer("glPrimitiveRestartIndex");
				pfnGlCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATA)lookupFunctionPointer("glCopyBufferSubData");
				pfnGlGetUniformIndices = (PFNGLGETUNIFORMINDICES)lookupFunctionPointer("glGetUniformIndices");
				pfnGlGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIV)lookupFunctionPointer("glGetActiveUniformsiv");
				pfnGlGetActiveUniformName = (PFNGLGETACTIVEUNIFORMNAME)lookupFunctionPointer("glGetActiveUniformName");
				pfnGlGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEX)lookupFunctionPointer("glGetUniformBlockIndex");
				pfnGlGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIV)lookupFunctionPointer("glGetActiveUniformBlockiv");
				pfnGlGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAME)lookupFunctionPointer("glGetActiveUniformBlockName");
				pfnGlUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDING)lookupFunctionPointer("glUniformBlockBinding");
				pfnGlDrawElementsBaseVertex = (PFNGLDRAWELEMENTSBASEVERTEX)lookupFunctionPointer("glDrawElementsBaseVertex");
				pfnGlDrawRangeElementsBaseVertex = (PFNGLDRAWRANGEELEMENTSBASEVERTEX)lookupFunctionPointer("glDrawRangeElementsBaseVertex");
				pfnGlDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEX)lookupFunctionPointer("glDrawElementsInstancedBaseVertex");
				pfnGlMultiDrawElementsBaseVertex = (PFNGLMULTIDRAWELEMENTSBASEVERTEX)lookupFunctionPointer("glMultiDrawElementsBaseVertex");
				pfnGlProvokingVertex = (PFNGLPROVOKINGVERTEX)lookupFunctionPointer("glProvokingVertex");
				pfnGlFenceSync = (PFNGLFENCESYNC)lookupFunctionPointer("glFenceSync");
				pfnGlIsSync = (PFNGLISSYNC)lookupFunctionPointer("glIsSync");
				pfnGlDeleteSync = (PFNGLDELETESYNC)lookupFunctionPointer("glDeleteSync");
				pfnGlClientWaitSync = (PFNGLCLIENTWAITSYNC)lookupFunctionPointer("glClientWaitSync");
				pfnGlWaitSync = (PFNGLWAITSYNC)lookupFunctionPointer("glWaitSync");
				pfnGlGetInteger64v = (PFNGLGETINTEGER64V)lookupFunctionPointer("glGetInteger64v");
				pfnGlGetSynciv = (PFNGLGETSYNCIV)lookupFunctionPointer("glGetSynciv");
				pfnGlGetInteger64i_v = (PFNGLGETINTEGER64I_V)lookupFunctionPointer("glGetInteger64i_v");
				pfnGlGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64V)lookupFunctionPointer("glGetBufferParameteri64v");
				pfnGlFramebufferTexture = (PFNGLFRAMEBUFFERTEXTURE)lookupFunctionPointer("glFramebufferTexture");
				pfnGlTexImage2DMultisample = (PFNGLTEXIMAGE2DMULTISAMPLE)lookupFunctionPointer("glTexImage2DMultisample");
				pfnGlTexImage3DMultisample = (PFNGLTEXIMAGE3DMULTISAMPLE)lookupFunctionPointer("glTexImage3DMultisample");
				pfnGlGetMultisamplefv = (PFNGLGETMULTISAMPLEFV)lookupFunctionPointer("glGetMultisamplefv");
				pfnGlSampleMaski = (PFNGLSAMPLEMASKI)lookupFunctionPointer("glSampleMaski");
				pfnGlBindFragDataLocationIndexed = (PFNGLBINDFRAGDATALOCATIONINDEXED)lookupFunctionPointer("glBindFragDataLocationIndexed");
				pfnGlGetFragDataIndex = (PFNGLGETFRAGDATAINDEX)lookupFunctionPointer("glGetFragDataIndex");
				pfnGlGenSamplers = (PFNGLGENSAMPLERS)lookupFunctionPointer("glGenSamplers");
				pfnGlDeleteSamplers = (PFNGLDELETESAMPLERS)lookupFunctionPointer("glDeleteSamplers");
				pfnGlIsSampler = (PFNGLISSAMPLER)lookupFunctionPointer("glIsSampler");
				pfnGlBindSampler = (PFNGLBINDSAMPLER)lookupFunctionPointer("glBindSampler");
				pfnGlSamplerParameteri = (PFNGLSAMPLERPARAMETERI)lookupFunctionPointer("glSamplerParameteri");
				pfnGlSamplerParameteriv = (PFNGLSAMPLERPARAMETERIV)lookupFunctionPointer("glSamplerParameteriv");
				pfnGlSamplerParameterf = (PFNGLSAMPLERPARAMETERF)lookupFunctionPointer("glSamplerParameterf");
				pfnGlSamplerParameterfv = (PFNGLSAMPLERPARAMETERFV)lookupFunctionPointer("glSamplerParameterfv");
				pfnGlSamplerParameterIiv = (PFNGLSAMPLERPARAMETERIIV)lookupFunctionPointer("glSamplerParameterIiv");
				pfnGlSamplerParameterIuiv = (PFNGLSAMPLERPARAMETERIUIV)lookupFunctionPointer("glSamplerParameterIuiv");
				pfnGlGetSamplerParameteriv = (PFNGLGETSAMPLERPARAMETERIV)lookupFunctionPointer("glGetSamplerParameteriv");
				pfnGlGetSamplerParameterIiv = (PFNGLGETSAMPLERPARAMETERIIV)lookupFunctionPointer("glGetSamplerParameterIiv");
				pfnGlGetSamplerParameterfv = (PFNGLGETSAMPLERPARAMETERFV)lookupFunctionPointer("glGetSamplerParameterfv");
				pfnGlGetSamplerParameterIuiv = (PFNGLGETSAMPLERPARAMETERIUIV)lookupFunctionPointer("glGetSamplerParameterIuiv");
				pfnGlQueryCounter = (PFNGLQUERYCOUNTER)lookupFunctionPointer("glQueryCounter");
				pfnGlGetQueryObjecti64v = (PFNGLGETQUERYOBJECTI64V)lookupFunctionPointer("glGetQueryObjecti64v");
				pfnGlGetQueryObjectui64v = (PFNGLGETQUERYOBJECTUI64V)lookupFunctionPointer("glGetQueryObjectui64v");
				pfnGlVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISOR)lookupFunctionPointer("glVertexAttribDivisor");
				pfnGlVertexAttribP1ui = (PFNGLVERTEXATTRIBP1UI)lookupFunctionPointer("glVertexAttribP1ui");
				pfnGlVertexAttribP1uiv = (PFNGLVERTEXATTRIBP1UIV)lookupFunctionPointer("glVertexAttribP1uiv");
				pfnGlVertexAttribP2ui = (PFNGLVERTEXATTRIBP2UI)lookupFunctionPointer("glVertexAttribP2ui");
				pfnGlVertexAttribP2uiv = (PFNGLVERTEXATTRIBP2UIV)lookupFunctionPointer("glVertexAttribP2uiv");
				pfnGlVertexAttribP3ui = (PFNGLVERTEXATTRIBP3UI)lookupFunctionPointer("glVertexAttribP3ui");
				pfnGlVertexAttribP3uiv = (PFNGLVERTEXATTRIBP3UIV)lookupFunctionPointer("glVertexAttribP3uiv");
				pfnGlVertexAttribP4ui = (PFNGLVERTEXATTRIBP4UI)lookupFunctionPointer("glVertexAttribP4ui");
				pfnGlVertexAttribP4uiv = (PFNGLVERTEXATTRIBP4UIV)lookupFunctionPointer("glVertexAttribP4uiv");
				pfnGlVertexP2ui = (PFNGLVERTEXP2UI)lookupFunctionPointer("glVertexP2ui");
				pfnGlVertexP2uiv = (PFNGLVERTEXP2UIV)lookupFunctionPointer("glVertexP2uiv");
				pfnGlVertexP3ui = (PFNGLVERTEXP3UI)lookupFunctionPointer("glVertexP3ui");
				pfnGlVertexP3uiv = (PFNGLVERTEXP3UIV)lookupFunctionPointer("glVertexP3uiv");
				pfnGlVertexP4ui = (PFNGLVERTEXP4UI)lookupFunctionPointer("glVertexP4ui");
				pfnGlVertexP4uiv = (PFNGLVERTEXP4UIV)lookupFunctionPointer("glVertexP4uiv");
				pfnGlTexCoordP1ui = (PFNGLTEXCOORDP1UI)lookupFunctionPointer("glTexCoordP1ui");
				pfnGlTexCoordP1uiv = (PFNGLTEXCOORDP1UIV)lookupFunctionPointer("glTexCoordP1uiv");
				pfnGlTexCoordP2ui = (PFNGLTEXCOORDP2UI)lookupFunctionPointer("glTexCoordP2ui");
				pfnGlTexCoordP2uiv = (PFNGLTEXCOORDP2UIV)lookupFunctionPointer("glTexCoordP2uiv");
				pfnGlTexCoordP3ui = (PFNGLTEXCOORDP3UI)lookupFunctionPointer("glTexCoordP3ui");
				pfnGlTexCoordP3uiv = (PFNGLTEXCOORDP3UIV)lookupFunctionPointer("glTexCoordP3uiv");
				pfnGlTexCoordP4ui = (PFNGLTEXCOORDP4UI)lookupFunctionPointer("glTexCoordP4ui");
				pfnGlTexCoordP4uiv = (PFNGLTEXCOORDP4UIV)lookupFunctionPointer("glTexCoordP4uiv");
				pfnGlMultiTexCoordP1ui = (PFNGLMULTITEXCOORDP1UI)lookupFunctionPointer("glMultiTexCoordP1ui");
				pfnGlMultiTexCoordP1uiv = (PFNGLMULTITEXCOORDP1UIV)lookupFunctionPointer("glMultiTexCoordP1uiv");
				pfnGlMultiTexCoordP2ui = (PFNGLMULTITEXCOORDP2UI)lookupFunctionPointer("glMultiTexCoordP2ui");
				pfnGlMultiTexCoordP2uiv = (PFNGLMULTITEXCOORDP2UIV)lookupFunctionPointer("glMultiTexCoordP2uiv");
				pfnGlMultiTexCoordP3ui = (PFNGLMULTITEXCOORDP3UI)lookupFunctionPointer("glMultiTexCoordP3ui");
				pfnGlMultiTexCoordP3uiv = (PFNGLMULTITEXCOORDP3UIV)lookupFunctionPointer("glMultiTexCoordP3uiv");
				pfnGlMultiTexCoordP4ui = (PFNGLMULTITEXCOORDP4UI)lookupFunctionPointer("glMultiTexCoordP4ui");
				pfnGlMultiTexCoordP4uiv = (PFNGLMULTITEXCOORDP4UIV)lookupFunctionPointer("glMultiTexCoordP4uiv");
				pfnGlNormalP3ui = (PFNGLNORMALP3UI)lookupFunctionPointer("glNormalP3ui");
				pfnGlNormalP3uiv = (PFNGLNORMALP3UIV)lookupFunctionPointer("glNormalP3uiv");
				pfnGlColorP3ui = (PFNGLCOLORP3UI)lookupFunctionPointer("glColorP3ui");
				pfnGlColorP3uiv = (PFNGLCOLORP3UIV)lookupFunctionPointer("glColorP3uiv");
				pfnGlColorP4ui = (PFNGLCOLORP4UI)lookupFunctionPointer("glColorP4ui");
				pfnGlColorP4uiv = (PFNGLCOLORP4UIV)lookupFunctionPointer("glColorP4uiv");
				pfnGlSecondaryColorP3ui = (PFNGLSECONDARYCOLORP3UI)lookupFunctionPointer("glSecondaryColorP3ui");
				pfnGlSecondaryColorP3uiv = (PFNGLSECONDARYCOLORP3UIV)lookupFunctionPointer("glSecondaryColorP3uiv");
				pfnGlMinSampleShading = (PFNGLMINSAMPLESHADING)lookupFunctionPointer("glMinSampleShading");
				pfnGlBlendEquationi = (PFNGLBLENDEQUATIONI)lookupFunctionPointer("glBlendEquationi");
				pfnGlBlendEquationSeparatei = (PFNGLBLENDEQUATIONSEPARATEI)lookupFunctionPointer("glBlendEquationSeparatei");
				pfnGlBlendFunci = (PFNGLBLENDFUNCI)lookupFunctionPointer("glBlendFunci");
				pfnGlBlendFuncSeparatei = (PFNGLBLENDFUNCSEPARATEI)lookupFunctionPointer("glBlendFuncSeparatei");
				pfnGlDrawArraysIndirect = (PFNGLDRAWARRAYSINDIRECT)lookupFunctionPointer("glDrawArraysIndirect");
				pfnGlDrawElementsIndirect = (PFNGLDRAWELEMENTSINDIRECT)lookupFunctionPointer("glDrawElementsIndirect");
				pfnGlUniform1d = (PFNGLUNIFORM1D)lookupFunctionPointer("glUniform1d");
				pfnGlUniform2d = (PFNGLUNIFORM2D)lookupFunctionPointer("glUniform2d");
				pfnGlUniform3d = (PFNGLUNIFORM3D)lookupFunctionPointer("glUniform3d");
				pfnGlUniform4d = (PFNGLUNIFORM4D)lookupFunctionPointer("glUniform4d");
				pfnGlUniform1dv = (PFNGLUNIFORM1DV)lookupFunctionPointer("glUniform1dv");
				pfnGlUniform2dv = (PFNGLUNIFORM2DV)lookupFunctionPointer("glUniform2dv");
				pfnGlUniform3dv = (PFNGLUNIFORM3DV)lookupFunctionPointer("glUniform3dv");
				pfnGlUniform4dv = (PFNGLUNIFORM4DV)lookupFunctionPointer("glUniform4dv");
				pfnGlUniformMatrix2dv = (PFNGLUNIFORMMATRIX2DV)lookupFunctionPointer("glUniformMatrix2dv");
				pfnGlUniformMatrix3dv = (PFNGLUNIFORMMATRIX3DV)lookupFunctionPointer("glUniformMatrix3dv");
				pfnGlUniformMatrix4dv = (PFNGLUNIFORMMATRIX4DV)lookupFunctionPointer("glUniformMatrix4dv");
				pfnGlUniformMatrix2x3dv = (PFNGLUNIFORMMATRIX2X3DV)lookupFunctionPointer("glUniformMatrix2x3dv");
				pfnGlUniformMatrix2x4dv = (PFNGLUNIFORMMATRIX2X4DV)lookupFunctionPointer("glUniformMatrix2x4dv");
				pfnGlUniformMatrix3x2dv = (PFNGLUNIFORMMATRIX3X2DV)lookupFunctionPointer("glUniformMatrix3x2dv");
				pfnGlUniformMatrix3x4dv = (PFNGLUNIFORMMATRIX3X4DV)lookupFunctionPointer("glUniformMatrix3x4dv");
				pfnGlUniformMatrix4x2dv = (PFNGLUNIFORMMATRIX4X2DV)lookupFunctionPointer("glUniformMatrix4x2dv");
				pfnGlUniformMatrix4x3dv = (PFNGLUNIFORMMATRIX4X3DV)lookupFunctionPointer("glUniformMatrix4x3dv");
				pfnGlGetUniformdv = (PFNGLGETUNIFORMDV)lookupFunctionPointer("glGetUniformdv");
				pfnGlGetSubroutineUniformLocation = (PFNGLGETSUBROUTINEUNIFORMLOCATION)lookupFunctionPointer("glGetSubroutineUniformLocation");
				pfnGlGetSubroutineIndex = (PFNGLGETSUBROUTINEINDEX)lookupFunctionPointer("glGetSubroutineIndex");
				pfnGlGetActiveSubroutineUniformiv = (PFNGLGETACTIVESUBROUTINEUNIFORMIV)lookupFunctionPointer("glGetActiveSubroutineUniformiv");
				pfnGlGetActiveSubroutineUniformName = (PFNGLGETACTIVESUBROUTINEUNIFORMNAME)lookupFunctionPointer("glGetActiveSubroutineUniformName");
				pfnGlGetActiveSubroutineName = (PFNGLGETACTIVESUBROUTINENAME)lookupFunctionPointer("glGetActiveSubroutineName");
				pfnGlUniformSubroutinesuiv = (PFNGLUNIFORMSUBROUTINESUIV)lookupFunctionPointer("glUniformSubroutinesuiv");
				pfnGlGetUniformSubroutineuiv = (PFNGLGETUNIFORMSUBROUTINEUIV)lookupFunctionPointer("glGetUniformSubroutineuiv");
				pfnGlGetProgramStageiv = (PFNGLGETPROGRAMSTAGEIV)lookupFunctionPointer("glGetProgramStageiv");
				pfnGlPatchParameteri = (PFNGLPATCHPARAMETERI)lookupFunctionPointer("glPatchParameteri");
				pfnGlPatchParameterfv = (PFNGLPATCHPARAMETERFV)lookupFunctionPointer("glPatchParameterfv");
				pfnGlBindTransformFeedback = (PFNGLBINDTRANSFORMFEEDBACK)lookupFunctionPointer("glBindTransformFeedback");
				pfnGlDeleteTransformFeedbacks = (PFNGLDELETETRANSFORMFEEDBACKS)lookupFunctionPointer("glDeleteTransformFeedbacks");
				pfnGlGenTransformFeedbacks = (PFNGLGENTRANSFORMFEEDBACKS)lookupFunctionPointer("glGenTransformFeedbacks");
				pfnGlIsTransformFeedback = (PFNGLISTRANSFORMFEEDBACK)lookupFunctionPointer("glIsTransformFeedback");
				pfnGlPauseTransformFeedback = (PFNGLPAUSETRANSFORMFEEDBACK)lookupFunctionPointer("glPauseTransformFeedback");
				pfnGlResumeTransformFeedback = (PFNGLRESUMETRANSFORMFEEDBACK)lookupFunctionPointer("glResumeTransformFeedback");
				pfnGlDrawTransformFeedback = (PFNGLDRAWTRANSFORMFEEDBACK)lookupFunctionPointer("glDrawTransformFeedback");
				pfnGlDrawTransformFeedbackStream = (PFNGLDRAWTRANSFORMFEEDBACKSTREAM)lookupFunctionPointer("glDrawTransformFeedbackStream");
				pfnGlBeginQueryIndexed = (PFNGLBEGINQUERYINDEXED)lookupFunctionPointer("glBeginQueryIndexed");
				pfnGlEndQueryIndexed = (PFNGLENDQUERYINDEXED)lookupFunctionPointer("glEndQueryIndexed");
				pfnGlGetQueryIndexediv = (PFNGLGETQUERYINDEXEDIV)lookupFunctionPointer("glGetQueryIndexediv");
				pfnGlReleaseShaderCompiler = (PFNGLRELEASESHADERCOMPILER)lookupFunctionPointer("glReleaseShaderCompiler");
				pfnGlShaderBinary = (PFNGLSHADERBINARY)lookupFunctionPointer("glShaderBinary");
				pfnGlGetShaderPrecisionFormat = (PFNGLGETSHADERPRECISIONFORMAT)lookupFunctionPointer("glGetShaderPrecisionFormat");
				pfnGlDepthRangef = (PFNGLDEPTHRANGEF)lookupFunctionPointer("glDepthRangef");
				pfnGlClearDepthf = (PFNGLCLEARDEPTHF)lookupFunctionPointer("glClearDepthf");
				pfnGlGetProgramBinary = (PFNGLGETPROGRAMBINARY)lookupFunctionPointer("glGetProgramBinary");
				pfnGlProgramBinary = (PFNGLPROGRAMBINARY)lookupFunctionPointer("glProgramBinary");
				pfnGlProgramParameteri = (PFNGLPROGRAMPARAMETERI)lookupFunctionPointer("glProgramParameteri");
				pfnGlUseProgramStages = (PFNGLUSEPROGRAMSTAGES)lookupFunctionPointer("glUseProgramStages");
				pfnGlActiveShaderProgram = (PFNGLACTIVESHADERPROGRAM)lookupFunctionPointer("glActiveShaderProgram");
				pfnGlCreateShaderProgramv = (PFNGLCREATESHADERPROGRAMV)lookupFunctionPointer("glCreateShaderProgramv");
				pfnGlBindProgramPipeline = (PFNGLBINDPROGRAMPIPELINE)lookupFunctionPointer("glBindProgramPipeline");
				pfnGlDeleteProgramPipelines = (PFNGLDELETEPROGRAMPIPELINES)lookupFunctionPointer("glDeleteProgramPipelines");
				pfnGlGenProgramPipelines = (PFNGLGENPROGRAMPIPELINES)lookupFunctionPointer("glGenProgramPipelines");
				pfnGlIsProgramPipeline = (PFNGLISPROGRAMPIPELINE)lookupFunctionPointer("glIsProgramPipeline");
				pfnGlGetProgramPipelineiv = (PFNGLGETPROGRAMPIPELINEIV)lookupFunctionPointer("glGetProgramPipelineiv");
				pfnGlProgramUniform1i = (PFNGLPROGRAMUNIFORM1I)lookupFunctionPointer("glProgramUniform1i");
				pfnGlProgramUniform1iv = (PFNGLPROGRAMUNIFORM1IV)lookupFunctionPointer("glProgramUniform1iv");
				pfnGlProgramUniform1f = (PFNGLPROGRAMUNIFORM1F)lookupFunctionPointer("glProgramUniform1f");
				pfnGlProgramUniform1fv = (PFNGLPROGRAMUNIFORM1FV)lookupFunctionPointer("glProgramUniform1fv");
				pfnGlProgramUniform1d = (PFNGLPROGRAMUNIFORM1D)lookupFunctionPointer("glProgramUniform1d");
				pfnGlProgramUniform1dv = (PFNGLPROGRAMUNIFORM1DV)lookupFunctionPointer("glProgramUniform1dv");
				pfnGlProgramUniform1ui = (PFNGLPROGRAMUNIFORM1UI)lookupFunctionPointer("glProgramUniform1ui");
				pfnGlProgramUniform1uiv = (PFNGLPROGRAMUNIFORM1UIV)lookupFunctionPointer("glProgramUniform1uiv");
				pfnGlProgramUniform2i = (PFNGLPROGRAMUNIFORM2I)lookupFunctionPointer("glProgramUniform2i");
				pfnGlProgramUniform2iv = (PFNGLPROGRAMUNIFORM2IV)lookupFunctionPointer("glProgramUniform2iv");
				pfnGlProgramUniform2f = (PFNGLPROGRAMUNIFORM2F)lookupFunctionPointer("glProgramUniform2f");
				pfnGlProgramUniform2fv = (PFNGLPROGRAMUNIFORM2FV)lookupFunctionPointer("glProgramUniform2fv");
				pfnGlProgramUniform2d = (PFNGLPROGRAMUNIFORM2D)lookupFunctionPointer("glProgramUniform2d");
				pfnGlProgramUniform2dv = (PFNGLPROGRAMUNIFORM2DV)lookupFunctionPointer("glProgramUniform2dv");
				pfnGlProgramUniform2ui = (PFNGLPROGRAMUNIFORM2UI)lookupFunctionPointer("glProgramUniform2ui");
				pfnGlProgramUniform2uiv = (PFNGLPROGRAMUNIFORM2UIV)lookupFunctionPointer("glProgramUniform2uiv");
				pfnGlProgramUniform3i = (PFNGLPROGRAMUNIFORM3I)lookupFunctionPointer("glProgramUniform3i");
				pfnGlProgramUniform3iv = (PFNGLPROGRAMUNIFORM3IV)lookupFunctionPointer("glProgramUniform3iv");
				pfnGlProgramUniform3f = (PFNGLPROGRAMUNIFORM3F)lookupFunctionPointer("glProgramUniform3f");
				pfnGlProgramUniform3fv = (PFNGLPROGRAMUNIFORM3FV)lookupFunctionPointer("glProgramUniform3fv");
				pfnGlProgramUniform3d = (PFNGLPROGRAMUNIFORM3D)lookupFunctionPointer("glProgramUniform3d");
				pfnGlProgramUniform3dv = (PFNGLPROGRAMUNIFORM3DV)lookupFunctionPointer("glProgramUniform3dv");
				pfnGlProgramUniform3ui = (PFNGLPROGRAMUNIFORM3UI)lookupFunctionPointer("glProgramUniform3ui");
				pfnGlProgramUniform3uiv = (PFNGLPROGRAMUNIFORM3UIV)lookupFunctionPointer("glProgramUniform3uiv");
				pfnGlProgramUniform4i = (PFNGLPROGRAMUNIFORM4I)lookupFunctionPointer("glProgramUniform4i");
				pfnGlProgramUniform4iv = (PFNGLPROGRAMUNIFORM4IV)lookupFunctionPointer("glProgramUniform4iv");
				pfnGlProgramUniform4f = (PFNGLPROGRAMUNIFORM4F)lookupFunctionPointer("glProgramUniform4f");
				pfnGlProgramUniform4fv = (PFNGLPROGRAMUNIFORM4FV)lookupFunctionPointer("glProgramUniform4fv");
				pfnGlProgramUniform4d = (PFNGLPROGRAMUNIFORM4D)lookupFunctionPointer("glProgramUniform4d");
				pfnGlProgramUniform4dv = (PFNGLPROGRAMUNIFORM4DV)lookupFunctionPointer("glProgramUniform4dv");
				pfnGlProgramUniform4ui = (PFNGLPROGRAMUNIFORM4UI)lookupFunctionPointer("glProgramUniform4ui");
				pfnGlProgramUniform4uiv = (PFNGLPROGRAMUNIFORM4UIV)lookupFunctionPointer("glProgramUniform4uiv");
				pfnGlProgramUniformMatrix2fv = (PFNGLPROGRAMUNIFORMMATRIX2FV)lookupFunctionPointer("glProgramUniformMatrix2fv");
				pfnGlProgramUniformMatrix3fv = (PFNGLPROGRAMUNIFORMMATRIX3FV)lookupFunctionPointer("glProgramUniformMatrix3fv");
				pfnGlProgramUniformMatrix4fv = (PFNGLPROGRAMUNIFORMMATRIX4FV)lookupFunctionPointer("glProgramUniformMatrix4fv");
				pfnGlProgramUniformMatrix2dv = (PFNGLPROGRAMUNIFORMMATRIX2DV)lookupFunctionPointer("glProgramUniformMatrix2dv");
				pfnGlProgramUniformMatrix3dv = (PFNGLPROGRAMUNIFORMMATRIX3DV)lookupFunctionPointer("glProgramUniformMatrix3dv");
				pfnGlProgramUniformMatrix4dv = (PFNGLPROGRAMUNIFORMMATRIX4DV)lookupFunctionPointer("glProgramUniformMatrix4dv");
				pfnGlProgramUniformMatrix2x3fv = (PFNGLPROGRAMUNIFORMMATRIX2X3FV)lookupFunctionPointer("glProgramUniformMatrix2x3fv");
				pfnGlProgramUniformMatrix3x2fv = (PFNGLPROGRAMUNIFORMMATRIX3X2FV)lookupFunctionPointer("glProgramUniformMatrix3x2fv");
				pfnGlProgramUniformMatrix2x4fv = (PFNGLPROGRAMUNIFORMMATRIX2X4FV)lookupFunctionPointer("glProgramUniformMatrix2x4fv");
				pfnGlProgramUniformMatrix4x2fv = (PFNGLPROGRAMUNIFORMMATRIX4X2FV)lookupFunctionPointer("glProgramUniformMatrix4x2fv");
				pfnGlProgramUniformMatrix3x4fv = (PFNGLPROGRAMUNIFORMMATRIX3X4FV)lookupFunctionPointer("glProgramUniformMatrix3x4fv");
				pfnGlProgramUniformMatrix4x3fv = (PFNGLPROGRAMUNIFORMMATRIX4X3FV)lookupFunctionPointer("glProgramUniformMatrix4x3fv");
				pfnGlProgramUniformMatrix2x3dv = (PFNGLPROGRAMUNIFORMMATRIX2X3DV)lookupFunctionPointer("glProgramUniformMatrix2x3dv");
				pfnGlProgramUniformMatrix3x2dv = (PFNGLPROGRAMUNIFORMMATRIX3X2DV)lookupFunctionPointer("glProgramUniformMatrix3x2dv");
				pfnGlProgramUniformMatrix2x4dv = (PFNGLPROGRAMUNIFORMMATRIX2X4DV)lookupFunctionPointer("glProgramUniformMatrix2x4dv");
				pfnGlProgramUniformMatrix4x2dv = (PFNGLPROGRAMUNIFORMMATRIX4X2DV)lookupFunctionPointer("glProgramUniformMatrix4x2dv");
				pfnGlProgramUniformMatrix3x4dv = (PFNGLPROGRAMUNIFORMMATRIX3X4DV)lookupFunctionPointer("glProgramUniformMatrix3x4dv");
				pfnGlProgramUniformMatrix4x3dv = (PFNGLPROGRAMUNIFORMMATRIX4X3DV)lookupFunctionPointer("glProgramUniformMatrix4x3dv");
				pfnGlValidateProgramPipeline = (PFNGLVALIDATEPROGRAMPIPELINE)lookupFunctionPointer("glValidateProgramPipeline");
				pfnGlGetProgramPipelineInfoLog = (PFNGLGETPROGRAMPIPELINEINFOLOG)lookupFunctionPointer("glGetProgramPipelineInfoLog");
				pfnGlVertexAttribL1d = (PFNGLVERTEXATTRIBL1D)lookupFunctionPointer("glVertexAttribL1d");
				pfnGlVertexAttribL2d = (PFNGLVERTEXATTRIBL2D)lookupFunctionPointer("glVertexAttribL2d");
				pfnGlVertexAttribL3d = (PFNGLVERTEXATTRIBL3D)lookupFunctionPointer("glVertexAttribL3d");
				pfnGlVertexAttribL4d = (PFNGLVERTEXATTRIBL4D)lookupFunctionPointer("glVertexAttribL4d");
				pfnGlVertexAttribL1dv = (PFNGLVERTEXATTRIBL1DV)lookupFunctionPointer("glVertexAttribL1dv");
				pfnGlVertexAttribL2dv = (PFNGLVERTEXATTRIBL2DV)lookupFunctionPointer("glVertexAttribL2dv");
				pfnGlVertexAttribL3dv = (PFNGLVERTEXATTRIBL3DV)lookupFunctionPointer("glVertexAttribL3dv");
				pfnGlVertexAttribL4dv = (PFNGLVERTEXATTRIBL4DV)lookupFunctionPointer("glVertexAttribL4dv");
				pfnGlVertexAttribLPointer = (PFNGLVERTEXATTRIBLPOINTER)lookupFunctionPointer("glVertexAttribLPointer");
				pfnGlGetVertexAttribLdv = (PFNGLGETVERTEXATTRIBLDV)lookupFunctionPointer("glGetVertexAttribLdv");
				pfnGlViewportArrayv = (PFNGLVIEWPORTARRAYV)lookupFunctionPointer("glViewportArrayv");
				pfnGlViewportIndexedf = (PFNGLVIEWPORTINDEXEDF)lookupFunctionPointer("glViewportIndexedf");
				pfnGlViewportIndexedfv = (PFNGLVIEWPORTINDEXEDFV)lookupFunctionPointer("glViewportIndexedfv");
				pfnGlScissorArrayv = (PFNGLSCISSORARRAYV)lookupFunctionPointer("glScissorArrayv");
				pfnGlScissorIndexed = (PFNGLSCISSORINDEXED)lookupFunctionPointer("glScissorIndexed");
				pfnGlScissorIndexedv = (PFNGLSCISSORINDEXEDV)lookupFunctionPointer("glScissorIndexedv");
				pfnGlDepthRangeArrayv = (PFNGLDEPTHRANGEARRAYV)lookupFunctionPointer("glDepthRangeArrayv");
				pfnGlDepthRangeIndexed = (PFNGLDEPTHRANGEINDEXED)lookupFunctionPointer("glDepthRangeIndexed");
				pfnGlGetFloati_v = (PFNGLGETFLOATI_V)lookupFunctionPointer("glGetFloati_v");
				pfnGlGetDoublei_v = (PFNGLGETDOUBLEI_V)lookupFunctionPointer("glGetDoublei_v");
				pfnGlDrawArraysInstancedBaseInstance = (PFNGLDRAWARRAYSINSTANCEDBASEINSTANCE)lookupFunctionPointer("glDrawArraysInstancedBaseInstance");
				pfnGlDrawElementsInstancedBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCE)lookupFunctionPointer("glDrawElementsInstancedBaseInstance");
				pfnGlDrawElementsInstancedBaseVertexBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCE)lookupFunctionPointer("glDrawElementsInstancedBaseVertexBaseInstance");
				pfnGlGetInternalformativ = (PFNGLGETINTERNALFORMATIV)lookupFunctionPointer("glGetInternalformativ");
				pfnGlGetActiveAtomicCounterBufferiv = (PFNGLGETACTIVEATOMICCOUNTERBUFFERIV)lookupFunctionPointer("glGetActiveAtomicCounterBufferiv");
				pfnGlBindImageTexture = (PFNGLBINDIMAGETEXTURE)lookupFunctionPointer("glBindImageTexture");
				pfnGlMemoryBarrier = (PFNGLMEMORYBARRIER)lookupFunctionPointer("glMemoryBarrier");
				pfnGlTexStorage1D = (PFNGLTEXSTORAGE1D)lookupFunctionPointer("glTexStorage1D");
				pfnGlTexStorage2D = (PFNGLTEXSTORAGE2D)lookupFunctionPointer("glTexStorage2D");
				pfnGlTexStorage3D = (PFNGLTEXSTORAGE3D)lookupFunctionPointer("glTexStorage3D");
				pfnGlDrawTransformFeedbackInstanced = (PFNGLDRAWTRANSFORMFEEDBACKINSTANCED)lookupFunctionPointer("glDrawTransformFeedbackInstanced");
				pfnGlDrawTransformFeedbackStreamInstanced = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCED)lookupFunctionPointer("glDrawTransformFeedbackStreamInstanced");
				pfnGlClearBufferData = (PFNGLCLEARBUFFERDATA)lookupFunctionPointer("glClearBufferData");
				pfnGlClearBufferSubData = (PFNGLCLEARBUFFERSUBDATA)lookupFunctionPointer("glClearBufferSubData");
				pfnGlDispatchCompute = (PFNGLDISPATCHCOMPUTE)lookupFunctionPointer("glDispatchCompute");
				pfnGlDispatchComputeIndirect = (PFNGLDISPATCHCOMPUTEINDIRECT)lookupFunctionPointer("glDispatchComputeIndirect");
				pfnGlCopyImageSubData = (PFNGLCOPYIMAGESUBDATA)lookupFunctionPointer("glCopyImageSubData");
				pfnGlFramebufferParameteri = (PFNGLFRAMEBUFFERPARAMETERI)lookupFunctionPointer("glFramebufferParameteri");
				pfnGlGetFramebufferParameteriv = (PFNGLGETFRAMEBUFFERPARAMETERIV)lookupFunctionPointer("glGetFramebufferParameteriv");
				pfnGlGetInternalformati64v = (PFNGLGETINTERNALFORMATI64V)lookupFunctionPointer("glGetInternalformati64v");
				pfnGlInvalidateTexSubImage = (PFNGLINVALIDATETEXSUBIMAGE)lookupFunctionPointer("glInvalidateTexSubImage");
				pfnGlInvalidateTexImage = (PFNGLINVALIDATETEXIMAGE)lookupFunctionPointer("glInvalidateTexImage");
				pfnGlInvalidateBufferSubData = (PFNGLINVALIDATEBUFFERSUBDATA)lookupFunctionPointer("glInvalidateBufferSubData");
				pfnGlInvalidateBufferData = (PFNGLINVALIDATEBUFFERDATA)lookupFunctionPointer("glInvalidateBufferData");
				pfnGlInvalidateFramebuffer = (PFNGLINVALIDATEFRAMEBUFFER)lookupFunctionPointer("glInvalidateFramebuffer");
				pfnGlInvalidateSubFramebuffer = (PFNGLINVALIDATESUBFRAMEBUFFER)lookupFunctionPointer("glInvalidateSubFramebuffer");
				pfnGlMultiDrawArraysIndirect = (PFNGLMULTIDRAWARRAYSINDIRECT)lookupFunctionPointer("glMultiDrawArraysIndirect");
				pfnGlMultiDrawElementsIndirect = (PFNGLMULTIDRAWELEMENTSINDIRECT)lookupFunctionPointer("glMultiDrawElementsIndirect");
				pfnGlGetProgramInterfaceiv = (PFNGLGETPROGRAMINTERFACEIV)lookupFunctionPointer("glGetProgramInterfaceiv");
				pfnGlGetProgramResourceIndex = (PFNGLGETPROGRAMRESOURCEINDEX)lookupFunctionPointer("glGetProgramResourceIndex");
				pfnGlGetProgramResourceName = (PFNGLGETPROGRAMRESOURCENAME)lookupFunctionPointer("glGetProgramResourceName");
				pfnGlGetProgramResourceiv = (PFNGLGETPROGRAMRESOURCEIV)lookupFunctionPointer("glGetProgramResourceiv");
				pfnGlGetProgramResourceLocation = (PFNGLGETPROGRAMRESOURCELOCATION)lookupFunctionPointer("glGetProgramResourceLocation");
				pfnGlGetProgramResourceLocationIndex = (PFNGLGETPROGRAMRESOURCELOCATIONINDEX)lookupFunctionPointer("glGetProgramResourceLocationIndex");
				pfnGlShaderStorageBlockBinding = (PFNGLSHADERSTORAGEBLOCKBINDING)lookupFunctionPointer("glShaderStorageBlockBinding");
				pfnGlTexBufferRange = (PFNGLTEXBUFFERRANGE)lookupFunctionPointer("glTexBufferRange");
				pfnGlTexStorage2DMultisample = (PFNGLTEXSTORAGE2DMULTISAMPLE)lookupFunctionPointer("glTexStorage2DMultisample");
				pfnGlTexStorage3DMultisample = (PFNGLTEXSTORAGE3DMULTISAMPLE)lookupFunctionPointer("glTexStorage3DMultisample");
				pfnGlTextureView = (PFNGLTEXTUREVIEW)lookupFunctionPointer("glTextureView");
				pfnGlBindVertexBuffer = (PFNGLBINDVERTEXBUFFER)lookupFunctionPointer("glBindVertexBuffer");
				pfnGlVertexAttribFormat = (PFNGLVERTEXATTRIBFORMAT)lookupFunctionPointer("glVertexAttribFormat");
				pfnGlVertexAttribIFormat = (PFNGLVERTEXATTRIBIFORMAT)lookupFunctionPointer("glVertexAttribIFormat");
				pfnGlVertexAttribLFormat = (PFNGLVERTEXATTRIBLFORMAT)lookupFunctionPointer("glVertexAttribLFormat");
				pfnGlVertexAttribBinding = (PFNGLVERTEXATTRIBBINDING)lookupFunctionPointer("glVertexAttribBinding");
				pfnGlVertexBindingDivisor = (PFNGLVERTEXBINDINGDIVISOR)lookupFunctionPointer("glVertexBindingDivisor");
				pfnGlDebugMessageControl = (PFNGLDEBUGMESSAGECONTROL)lookupFunctionPointer("glDebugMessageControl");
				pfnGlDebugMessageInsert = (PFNGLDEBUGMESSAGEINSERT)lookupFunctionPointer("glDebugMessageInsert");
				pfnGlDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACK)lookupFunctionPointer("glDebugMessageCallback");
				pfnGlGetDebugMessageLog = (PFNGLGETDEBUGMESSAGELOG)lookupFunctionPointer("glGetDebugMessageLog");
				pfnGlPushDebugGroup = (PFNGLPUSHDEBUGGROUP)lookupFunctionPointer("glPushDebugGroup");
				pfnGlPopDebugGroup = (PFNGLPOPDEBUGGROUP)lookupFunctionPointer("glPopDebugGroup");
				pfnGlObjectLabel = (PFNGLOBJECTLABEL)lookupFunctionPointer("glObjectLabel");
				pfnGlGetObjectLabel = (PFNGLGETOBJECTLABEL)lookupFunctionPointer("glGetObjectLabel");
				pfnGlObjectPtrLabel = (PFNGLOBJECTPTRLABEL)lookupFunctionPointer("glObjectPtrLabel");
				pfnGlGetObjectPtrLabel = (PFNGLGETOBJECTPTRLABEL)lookupFunctionPointer("glGetObjectPtrLabel");
				pfnGlGetPointerv = (PFNGLGETPOINTERV)lookupFunctionPointer("glGetPointerv");
				pfnGlBufferStorage = (PFNGLBUFFERSTORAGE)lookupFunctionPointer("glBufferStorage");
				pfnGlClearTexImage = (PFNGLCLEARTEXIMAGE)lookupFunctionPointer("glClearTexImage");
				pfnGlClearTexSubImage = (PFNGLCLEARTEXSUBIMAGE)lookupFunctionPointer("glClearTexSubImage");
				pfnGlBindBuffersBase = (PFNGLBINDBUFFERSBASE)lookupFunctionPointer("glBindBuffersBase");
				pfnGlBindBuffersRange = (PFNGLBINDBUFFERSRANGE)lookupFunctionPointer("glBindBuffersRange");
				pfnGlBindTextures = (PFNGLBINDTEXTURES)lookupFunctionPointer("glBindTextures");
				pfnGlBindSamplers = (PFNGLBINDSAMPLERS)lookupFunctionPointer("glBindSamplers");
				pfnGlBindImageTextures = (PFNGLBINDIMAGETEXTURES)lookupFunctionPointer("glBindImageTextures");
				pfnGlBindVertexBuffers = (PFNGLBINDVERTEXBUFFERS)lookupFunctionPointer("glBindVertexBuffers");
				pfnGlClipControl = (PFNGLCLIPCONTROL)lookupFunctionPointer("glClipControl");
				pfnGlCreateTransformFeedbacks = (PFNGLCREATETRANSFORMFEEDBACKS)lookupFunctionPointer("glCreateTransformFeedbacks");
				pfnGlTransformFeedbackBufferBase = (PFNGLTRANSFORMFEEDBACKBUFFERBASE)lookupFunctionPointer("glTransformFeedbackBufferBase");
				pfnGlTransformFeedbackBufferRange = (PFNGLTRANSFORMFEEDBACKBUFFERRANGE)lookupFunctionPointer("glTransformFeedbackBufferRange");
				pfnGlGetTransformFeedbackiv = (PFNGLGETTRANSFORMFEEDBACKIV)lookupFunctionPointer("glGetTransformFeedbackiv");
				pfnGlGetTransformFeedbacki_v = (PFNGLGETTRANSFORMFEEDBACKI_V)lookupFunctionPointer("glGetTransformFeedbacki_v");
				pfnGlGetTransformFeedbacki64_v = (PFNGLGETTRANSFORMFEEDBACKI64_V)lookupFunctionPointer("glGetTransformFeedbacki64_v");
				pfnGlCreateBuffers = (PFNGLCREATEBUFFERS)lookupFunctionPointer("glCreateBuffers");
				pfnGlNamedBufferStorage = (PFNGLNAMEDBUFFERSTORAGE)lookupFunctionPointer("glNamedBufferStorage");
				pfnGlNamedBufferData = (PFNGLNAMEDBUFFERDATA)lookupFunctionPointer("glNamedBufferData");
				pfnGlNamedBufferSubData = (PFNGLNAMEDBUFFERSUBDATA)lookupFunctionPointer("glNamedBufferSubData");
				pfnGlCopyNamedBufferSubData = (PFNGLCOPYNAMEDBUFFERSUBDATA)lookupFunctionPointer("glCopyNamedBufferSubData");
				pfnGlClearNamedBufferData = (PFNGLCLEARNAMEDBUFFERDATA)lookupFunctionPointer("glClearNamedBufferData");
				pfnGlClearNamedBufferSubData = (PFNGLCLEARNAMEDBUFFERSUBDATA)lookupFunctionPointer("glClearNamedBufferSubData");
				pfnGlMapNamedBuffer = (PFNGLMAPNAMEDBUFFER)lookupFunctionPointer("glMapNamedBuffer");
				pfnGlMapNamedBufferRange = (PFNGLMAPNAMEDBUFFERRANGE)lookupFunctionPointer("glMapNamedBufferRange");
				pfnGlUnmapNamedBuffer = (PFNGLUNMAPNAMEDBUFFER)lookupFunctionPointer("glUnmapNamedBuffer");
				pfnGlFlushMappedNamedBufferRange = (PFNGLFLUSHMAPPEDNAMEDBUFFERRANGE)lookupFunctionPointer("glFlushMappedNamedBufferRange");
				pfnGlGetNamedBufferParameteriv = (PFNGLGETNAMEDBUFFERPARAMETERIV)lookupFunctionPointer("glGetNamedBufferParameteriv");
				pfnGlGetNamedBufferParameteri64v = (PFNGLGETNAMEDBUFFERPARAMETERI64V)lookupFunctionPointer("glGetNamedBufferParameteri64v");
				pfnGlGetNamedBufferPointerv = (PFNGLGETNAMEDBUFFERPOINTERV)lookupFunctionPointer("glGetNamedBufferPointerv");
				pfnGlGetNamedBufferSubData = (PFNGLGETNAMEDBUFFERSUBDATA)lookupFunctionPointer("glGetNamedBufferSubData");
				pfnGlCreateFramebuffers = (PFNGLCREATEFRAMEBUFFERS)lookupFunctionPointer("glCreateFramebuffers");
				pfnGlNamedFramebufferRenderbuffer = (PFNGLNAMEDFRAMEBUFFERRENDERBUFFER)lookupFunctionPointer("glNamedFramebufferRenderbuffer");
				pfnGlNamedFramebufferParameteri = (PFNGLNAMEDFRAMEBUFFERPARAMETERI)lookupFunctionPointer("glNamedFramebufferParameteri");
				pfnGlNamedFramebufferTexture = (PFNGLNAMEDFRAMEBUFFERTEXTURE)lookupFunctionPointer("glNamedFramebufferTexture");
				pfnGlNamedFramebufferTextureLayer = (PFNGLNAMEDFRAMEBUFFERTEXTURELAYER)lookupFunctionPointer("glNamedFramebufferTextureLayer");
				pfnGlNamedFramebufferDrawBuffer = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFER)lookupFunctionPointer("glNamedFramebufferDrawBuffer");
				pfnGlNamedFramebufferDrawBuffers = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERS)lookupFunctionPointer("glNamedFramebufferDrawBuffers");
				pfnGlNamedFramebufferReadBuffer = (PFNGLNAMEDFRAMEBUFFERREADBUFFER)lookupFunctionPointer("glNamedFramebufferReadBuffer");
				pfnGlInvalidateNamedFramebufferData = (PFNGLINVALIDATENAMEDFRAMEBUFFERDATA)lookupFunctionPointer("glInvalidateNamedFramebufferData");
				pfnGlInvalidateNamedFramebufferSubData = (PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATA)lookupFunctionPointer("glInvalidateNamedFramebufferSubData");
				pfnGlClearNamedFramebufferiv = (PFNGLCLEARNAMEDFRAMEBUFFERIV)lookupFunctionPointer("glClearNamedFramebufferiv");
				pfnGlClearNamedFramebufferuiv = (PFNGLCLEARNAMEDFRAMEBUFFERUIV)lookupFunctionPointer("glClearNamedFramebufferuiv");
				pfnGlClearNamedFramebufferfv = (PFNGLCLEARNAMEDFRAMEBUFFERFV)lookupFunctionPointer("glClearNamedFramebufferfv");
				pfnGlClearNamedFramebufferfi = (PFNGLCLEARNAMEDFRAMEBUFFERFI)lookupFunctionPointer("glClearNamedFramebufferfi");
				pfnGlBlitNamedFramebuffer = (PFNGLBLITNAMEDFRAMEBUFFER)lookupFunctionPointer("glBlitNamedFramebuffer");
				pfnGlCheckNamedFramebufferStatus = (PFNGLCHECKNAMEDFRAMEBUFFERSTATUS)lookupFunctionPointer("glCheckNamedFramebufferStatus");
				pfnGlGetNamedFramebufferParameteriv = (PFNGLGETNAMEDFRAMEBUFFERPARAMETERIV)lookupFunctionPointer("glGetNamedFramebufferParameteriv");
				pfnGlGetNamedFramebufferAttachmentParameteriv = (PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIV)lookupFunctionPointer("glGetNamedFramebufferAttachmentParameteriv");
				pfnGlCreateRenderbuffers = (PFNGLCREATERENDERBUFFERS)lookupFunctionPointer("glCreateRenderbuffers");
				pfnGlNamedRenderbufferStorage = (PFNGLNAMEDRENDERBUFFERSTORAGE)lookupFunctionPointer("glNamedRenderbufferStorage");
				pfnGlNamedRenderbufferStorageMultisample = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLE)lookupFunctionPointer("glNamedRenderbufferStorageMultisample");
				pfnGlGetNamedRenderbufferParameteriv = (PFNGLGETNAMEDRENDERBUFFERPARAMETERIV)lookupFunctionPointer("glGetNamedRenderbufferParameteriv");
				pfnGlCreateTextures = (PFNGLCREATETEXTURES)lookupFunctionPointer("glCreateTextures");
				pfnGlTextureBuffer = (PFNGLTEXTUREBUFFER)lookupFunctionPointer("glTextureBuffer");
				pfnGlTextureBufferRange = (PFNGLTEXTUREBUFFERRANGE)lookupFunctionPointer("glTextureBufferRange");
				pfnGlTextureStorage1D = (PFNGLTEXTURESTORAGE1D)lookupFunctionPointer("glTextureStorage1D");
				pfnGlTextureStorage2D = (PFNGLTEXTURESTORAGE2D)lookupFunctionPointer("glTextureStorage2D");
				pfnGlTextureStorage3D = (PFNGLTEXTURESTORAGE3D)lookupFunctionPointer("glTextureStorage3D");
				pfnGlTextureStorage2DMultisample = (PFNGLTEXTURESTORAGE2DMULTISAMPLE)lookupFunctionPointer("glTextureStorage2DMultisample");
				pfnGlTextureStorage3DMultisample = (PFNGLTEXTURESTORAGE3DMULTISAMPLE)lookupFunctionPointer("glTextureStorage3DMultisample");
				pfnGlTextureSubImage1D = (PFNGLTEXTURESUBIMAGE1D)lookupFunctionPointer("glTextureSubImage1D");
				pfnGlTextureSubImage2D = (PFNGLTEXTURESUBIMAGE2D)lookupFunctionPointer("glTextureSubImage2D");
				pfnGlTextureSubImage3D = (PFNGLTEXTURESUBIMAGE3D)lookupFunctionPointer("glTextureSubImage3D");
				pfnGlCompressedTextureSubImage1D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE1D)lookupFunctionPointer("glCompressedTextureSubImage1D");
				pfnGlCompressedTextureSubImage2D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE2D)lookupFunctionPointer("glCompressedTextureSubImage2D");
				pfnGlCompressedTextureSubImage3D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE3D)lookupFunctionPointer("glCompressedTextureSubImage3D");
				pfnGlCopyTextureSubImage1D = (PFNGLCOPYTEXTURESUBIMAGE1D)lookupFunctionPointer("glCopyTextureSubImage1D");
				pfnGlCopyTextureSubImage2D = (PFNGLCOPYTEXTURESUBIMAGE2D)lookupFunctionPointer("glCopyTextureSubImage2D");
				pfnGlCopyTextureSubImage3D = (PFNGLCOPYTEXTURESUBIMAGE3D)lookupFunctionPointer("glCopyTextureSubImage3D");
				pfnGlTextureParameterf = (PFNGLTEXTUREPARAMETERF)lookupFunctionPointer("glTextureParameterf");
				pfnGlTextureParameterfv = (PFNGLTEXTUREPARAMETERFV)lookupFunctionPointer("glTextureParameterfv");
				pfnGlTextureParameteri = (PFNGLTEXTUREPARAMETERI)lookupFunctionPointer("glTextureParameteri");
				pfnGlTextureParameterIiv = (PFNGLTEXTUREPARAMETERIIV)lookupFunctionPointer("glTextureParameterIiv");
				pfnGlTextureParameterIuiv = (PFNGLTEXTUREPARAMETERIUIV)lookupFunctionPointer("glTextureParameterIuiv");
				pfnGlTextureParameteriv = (PFNGLTEXTUREPARAMETERIV)lookupFunctionPointer("glTextureParameteriv");
				pfnGlGenerateTextureMipmap = (PFNGLGENERATETEXTUREMIPMAP)lookupFunctionPointer("glGenerateTextureMipmap");
				pfnGlBindTextureUnit = (PFNGLBINDTEXTUREUNIT)lookupFunctionPointer("glBindTextureUnit");
				pfnGlGetTextureImage = (PFNGLGETTEXTUREIMAGE)lookupFunctionPointer("glGetTextureImage");
				pfnGlGetCompressedTextureImage = (PFNGLGETCOMPRESSEDTEXTUREIMAGE)lookupFunctionPointer("glGetCompressedTextureImage");
				pfnGlGetTextureLevelParameterfv = (PFNGLGETTEXTURELEVELPARAMETERFV)lookupFunctionPointer("glGetTextureLevelParameterfv");
				pfnGlGetTextureLevelParameteriv = (PFNGLGETTEXTURELEVELPARAMETERIV)lookupFunctionPointer("glGetTextureLevelParameteriv");
				pfnGlGetTextureParameterfv = (PFNGLGETTEXTUREPARAMETERFV)lookupFunctionPointer("glGetTextureParameterfv");
				pfnGlGetTextureParameterIiv = (PFNGLGETTEXTUREPARAMETERIIV)lookupFunctionPointer("glGetTextureParameterIiv");
				pfnGlGetTextureParameterIuiv = (PFNGLGETTEXTUREPARAMETERIUIV)lookupFunctionPointer("glGetTextureParameterIuiv");
				pfnGlGetTextureParameteriv = (PFNGLGETTEXTUREPARAMETERIV)lookupFunctionPointer("glGetTextureParameteriv");
				pfnGlCreateVertexArrays = (PFNGLCREATEVERTEXARRAYS)lookupFunctionPointer("glCreateVertexArrays");
				pfnGlDisableVertexArrayAttrib = (PFNGLDISABLEVERTEXARRAYATTRIB)lookupFunctionPointer("glDisableVertexArrayAttrib");
				pfnGlEnableVertexArrayAttrib = (PFNGLENABLEVERTEXARRAYATTRIB)lookupFunctionPointer("glEnableVertexArrayAttrib");
				pfnGlVertexArrayElementBuffer = (PFNGLVERTEXARRAYELEMENTBUFFER)lookupFunctionPointer("glVertexArrayElementBuffer");
				pfnGlVertexArrayVertexBuffer = (PFNGLVERTEXARRAYVERTEXBUFFER)lookupFunctionPointer("glVertexArrayVertexBuffer");
				pfnGlVertexArrayVertexBuffers = (PFNGLVERTEXARRAYVERTEXBUFFERS)lookupFunctionPointer("glVertexArrayVertexBuffers");
				pfnGlVertexArrayAttribBinding = (PFNGLVERTEXARRAYATTRIBBINDING)lookupFunctionPointer("glVertexArrayAttribBinding");
				pfnGlVertexArrayAttribFormat = (PFNGLVERTEXARRAYATTRIBFORMAT)lookupFunctionPointer("glVertexArrayAttribFormat");
				pfnGlVertexArrayAttribIFormat = (PFNGLVERTEXARRAYATTRIBIFORMAT)lookupFunctionPointer("glVertexArrayAttribIFormat");
				pfnGlVertexArrayAttribLFormat = (PFNGLVERTEXARRAYATTRIBLFORMAT)lookupFunctionPointer("glVertexArrayAttribLFormat");
				pfnGlVertexArrayBindingDivisor = (PFNGLVERTEXARRAYBINDINGDIVISOR)lookupFunctionPointer("glVertexArrayBindingDivisor");
				pfnGlGetVertexArrayiv = (PFNGLGETVERTEXARRAYIV)lookupFunctionPointer("glGetVertexArrayiv");
				pfnGlGetVertexArrayIndexediv = (PFNGLGETVERTEXARRAYINDEXEDIV)lookupFunctionPointer("glGetVertexArrayIndexediv");
				pfnGlGetVertexArrayIndexed64iv = (PFNGLGETVERTEXARRAYINDEXED64IV)lookupFunctionPointer("glGetVertexArrayIndexed64iv");
				pfnGlCreateSamplers = (PFNGLCREATESAMPLERS)lookupFunctionPointer("glCreateSamplers");
				pfnGlCreateProgramPipelines = (PFNGLCREATEPROGRAMPIPELINES)lookupFunctionPointer("glCreateProgramPipelines");
				pfnGlCreateQueries = (PFNGLCREATEQUERIES)lookupFunctionPointer("glCreateQueries");
				pfnGlGetQueryBufferObjecti64v = (PFNGLGETQUERYBUFFEROBJECTI64V)lookupFunctionPointer("glGetQueryBufferObjecti64v");
				pfnGlGetQueryBufferObjectiv = (PFNGLGETQUERYBUFFEROBJECTIV)lookupFunctionPointer("glGetQueryBufferObjectiv");
				pfnGlGetQueryBufferObjectui64v = (PFNGLGETQUERYBUFFEROBJECTUI64V)lookupFunctionPointer("glGetQueryBufferObjectui64v");
				pfnGlGetQueryBufferObjectuiv = (PFNGLGETQUERYBUFFEROBJECTUIV)lookupFunctionPointer("glGetQueryBufferObjectuiv");
				pfnGlMemoryBarrierByRegion = (PFNGLMEMORYBARRIERBYREGION)lookupFunctionPointer("glMemoryBarrierByRegion");
				pfnGlGetTextureSubImage = (PFNGLGETTEXTURESUBIMAGE)lookupFunctionPointer("glGetTextureSubImage");
				pfnGlGetCompressedTextureSubImage = (PFNGLGETCOMPRESSEDTEXTURESUBIMAGE)lookupFunctionPointer("glGetCompressedTextureSubImage");
				pfnGlGetGraphicsResetStatus = (PFNGLGETGRAPHICSRESETSTATUS)lookupFunctionPointer("glGetGraphicsResetStatus");
				pfnGlGetnCompressedTexImage = (PFNGLGETNCOMPRESSEDTEXIMAGE)lookupFunctionPointer("glGetnCompressedTexImage");
				pfnGlGetnTexImage = (PFNGLGETNTEXIMAGE)lookupFunctionPointer("glGetnTexImage");
				pfnGlGetnUniformdv = (PFNGLGETNUNIFORMDV)lookupFunctionPointer("glGetnUniformdv");
				pfnGlGetnUniformfv = (PFNGLGETNUNIFORMFV)lookupFunctionPointer("glGetnUniformfv");
				pfnGlGetnUniformiv = (PFNGLGETNUNIFORMIV)lookupFunctionPointer("glGetnUniformiv");
				pfnGlGetnUniformuiv = (PFNGLGETNUNIFORMUIV)lookupFunctionPointer("glGetnUniformuiv");
				pfnGlReadnPixels = (PFNGLREADNPIXELS)lookupFunctionPointer("glReadnPixels");
				pfnGlGetnMapdv = (PFNGLGETNMAPDV)lookupFunctionPointer("glGetnMapdv");
				pfnGlGetnMapfv = (PFNGLGETNMAPFV)lookupFunctionPointer("glGetnMapfv");
				pfnGlGetnMapiv = (PFNGLGETNMAPIV)lookupFunctionPointer("glGetnMapiv");
				pfnGlGetnPixelMapfv = (PFNGLGETNPIXELMAPFV)lookupFunctionPointer("glGetnPixelMapfv");
				pfnGlGetnPixelMapuiv = (PFNGLGETNPIXELMAPUIV)lookupFunctionPointer("glGetnPixelMapuiv");
				pfnGlGetnPixelMapusv = (PFNGLGETNPIXELMAPUSV)lookupFunctionPointer("glGetnPixelMapusv");
				pfnGlGetnPolygonStipple = (PFNGLGETNPOLYGONSTIPPLE)lookupFunctionPointer("glGetnPolygonStipple");
				pfnGlGetnColorTable = (PFNGLGETNCOLORTABLE)lookupFunctionPointer("glGetnColorTable");
				pfnGlGetnConvolutionFilter = (PFNGLGETNCONVOLUTIONFILTER)lookupFunctionPointer("glGetnConvolutionFilter");
				pfnGlGetnSeparableFilter = (PFNGLGETNSEPARABLEFILTER)lookupFunctionPointer("glGetnSeparableFilter");
				pfnGlGetnHistogram = (PFNGLGETNHISTOGRAM)lookupFunctionPointer("glGetnHistogram");
				pfnGlGetnMinmax = (PFNGLGETNMINMAX)lookupFunctionPointer("glGetnMinmax");
				pfnGlTextureBarrier = (PFNGLTEXTUREBARRIER)lookupFunctionPointer("glTextureBarrier");
				pfnGlSpecializeShader = (PFNGLSPECIALIZESHADER)lookupFunctionPointer("glSpecializeShader");
				pfnGlMultiDrawArraysIndirectCount = (PFNGLMULTIDRAWARRAYSINDIRECTCOUNT)lookupFunctionPointer("glMultiDrawArraysIndirectCount");
				pfnGlMultiDrawElementsIndirectCount = (PFNGLMULTIDRAWELEMENTSINDIRECTCOUNT)lookupFunctionPointer("glMultiDrawElementsIndirectCount");
				pfnGlPolygonOffsetClamp = (PFNGLPOLYGONOFFSETCLAMP)lookupFunctionPointer("glPolygonOffsetClamp");
			}
			
		}
		
		void glCullFace(GLenum mode) {
			return procs::pfnGlCullFace(mode);
		}
		void glFrontFace(GLenum mode) {
			return procs::pfnGlFrontFace(mode);
		}
		void glHint(GLenum target, GLenum mode) {
			return procs::pfnGlHint(target, mode);
		}
		void glLineWidth(GLfloat width) {
			return procs::pfnGlLineWidth(width);
		}
		void glPointSize(GLfloat size) {
			return procs::pfnGlPointSize(size);
		}
		void glPolygonMode(GLenum face, GLenum mode) {
			return procs::pfnGlPolygonMode(face, mode);
		}
		void glScissor(GLint x, GLint y, GLsizei width, GLsizei height) {
			return procs::pfnGlScissor(x, y, width, height);
		}
		void glTexParameterf(GLenum target, GLenum pname, GLfloat param) {
			return procs::pfnGlTexParameterf(target, pname, param);
		}
		void glTexParameterfv(GLenum target, GLenum pname, GLfloat * params) {
			return procs::pfnGlTexParameterfv(target, pname, params);
		}
		void glTexParameteri(GLenum target, GLenum pname, GLint param) {
			return procs::pfnGlTexParameteri(target, pname, param);
		}
		void glTexParameteriv(GLenum target, GLenum pname, GLint * params) {
			return procs::pfnGlTexParameteriv(target, pname, params);
		}
		void glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels) {
			return procs::pfnGlTexImage1D(target, level, internalformat, width, border, format, type, pixels);
		}
		void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels) {
			return procs::pfnGlTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
		}
		void glDrawBuffer(GLenum buf) {
			return procs::pfnGlDrawBuffer(buf);
		}
		void glClear(GLbitfield mask) {
			return procs::pfnGlClear(mask);
		}
		void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
			return procs::pfnGlClearColor(red, green, blue, alpha);
		}
		void glClearStencil(GLint s) {
			return procs::pfnGlClearStencil(s);
		}
		void glClearDepth(GLdouble depth) {
			return procs::pfnGlClearDepth(depth);
		}
		void glStencilMask(GLuint mask) {
			return procs::pfnGlStencilMask(mask);
		}
		void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
			return procs::pfnGlColorMask(red, green, blue, alpha);
		}
		void glDepthMask(GLboolean flag) {
			return procs::pfnGlDepthMask(flag);
		}
		void glDisable(GLenum cap) {
			return procs::pfnGlDisable(cap);
		}
		void glEnable(GLenum cap) {
			return procs::pfnGlEnable(cap);
		}
		void glFinish() {
			return procs::pfnGlFinish();
		}
		void glFlush() {
			return procs::pfnGlFlush();
		}
		void glBlendFunc(GLenum sfactor, GLenum dfactor) {
			return procs::pfnGlBlendFunc(sfactor, dfactor);
		}
		void glLogicOp(GLenum opcode) {
			return procs::pfnGlLogicOp(opcode);
		}
		void glStencilFunc(GLenum func, GLint ref, GLuint mask) {
			return procs::pfnGlStencilFunc(func, ref, mask);
		}
		void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) {
			return procs::pfnGlStencilOp(fail, zfail, zpass);
		}
		void glDepthFunc(GLenum func) {
			return procs::pfnGlDepthFunc(func);
		}
		void glPixelStoref(GLenum pname, GLfloat param) {
			return procs::pfnGlPixelStoref(pname, param);
		}
		void glPixelStorei(GLenum pname, GLint param) {
			return procs::pfnGlPixelStorei(pname, param);
		}
		void glReadBuffer(GLenum src) {
			return procs::pfnGlReadBuffer(src);
		}
		void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void * pixels) {
			return procs::pfnGlReadPixels(x, y, width, height, format, type, pixels);
		}
		void glGetBooleanv(GLenum pname, GLboolean * data) {
			return procs::pfnGlGetBooleanv(pname, data);
		}
		void glGetDoublev(GLenum pname, GLdouble * data) {
			return procs::pfnGlGetDoublev(pname, data);
		}
		GLenum glGetError() {
			return procs::pfnGlGetError();
		}
		void glGetFloatv(GLenum pname, GLfloat * data) {
			return procs::pfnGlGetFloatv(pname, data);
		}
		void glGetIntegerv(GLenum pname, GLint * data) {
			return procs::pfnGlGetIntegerv(pname, data);
		}
		GLubyte * glGetString(GLenum name) {
			return procs::pfnGlGetString(name);
		}
		void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void * pixels) {
			return procs::pfnGlGetTexImage(target, level, format, type, pixels);
		}
		void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params) {
			return procs::pfnGlGetTexParameterfv(target, pname, params);
		}
		void glGetTexParameteriv(GLenum target, GLenum pname, GLint * params) {
			return procs::pfnGlGetTexParameteriv(target, pname, params);
		}
		void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat * params) {
			return procs::pfnGlGetTexLevelParameterfv(target, level, pname, params);
		}
		void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint * params) {
			return procs::pfnGlGetTexLevelParameteriv(target, level, pname, params);
		}
		GLboolean glIsEnabled(GLenum cap) {
			return procs::pfnGlIsEnabled(cap);
		}
		void glDepthRange(GLdouble n, GLdouble f) {
			return procs::pfnGlDepthRange(n, f);
		}
		void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
			return procs::pfnGlViewport(x, y, width, height);
		}
		void glDrawArrays(GLenum mode, GLint first, GLsizei count) {
			return procs::pfnGlDrawArrays(mode, first, count);
		}
		void glDrawElements(GLenum mode, GLsizei count, GLenum type, const void * indices) {
			return procs::pfnGlDrawElements(mode, count, type, indices);
		}
		void glPolygonOffset(GLfloat factor, GLfloat units) {
			return procs::pfnGlPolygonOffset(factor, units);
		}
		void glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
			return procs::pfnGlCopyTexImage1D(target, level, internalformat, x, y, width, border);
		}
		void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
			return procs::pfnGlCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
		}
		void glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
			return procs::pfnGlCopyTexSubImage1D(target, level, xoffset, x, y, width);
		}
		void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
			return procs::pfnGlCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
		}
		void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels) {
			return procs::pfnGlTexSubImage1D(target, level, xoffset, width, format, type, pixels);
		}
		void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels) {
			return procs::pfnGlTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
		}
		void glBindTexture(GLenum target, GLuint texture) {
			return procs::pfnGlBindTexture(target, texture);
		}
		void glDeleteTextures(GLsizei n, GLuint * textures) {
			return procs::pfnGlDeleteTextures(n, textures);
		}
		void glGenTextures(GLsizei n, GLuint * textures) {
			return procs::pfnGlGenTextures(n, textures);
		}
		GLboolean glIsTexture(GLuint texture) {
			return procs::pfnGlIsTexture(texture);
		}
		void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices) {
			return procs::pfnGlDrawRangeElements(mode, start, end, count, type, indices);
		}
		void glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels) {
			return procs::pfnGlTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels);
		}
		void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels) {
			return procs::pfnGlTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
		}
		void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
			return procs::pfnGlCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height);
		}
		void glActiveTexture(GLenum texture) {
			return procs::pfnGlActiveTexture(texture);
		}
		void glSampleCoverage(GLfloat value, GLboolean invert) {
			return procs::pfnGlSampleCoverage(value, invert);
		}
		void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data) {
			return procs::pfnGlCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data);
		}
		void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data) {
			return procs::pfnGlCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
		}
		void glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * data) {
			return procs::pfnGlCompressedTexImage1D(target, level, internalformat, width, border, imageSize, data);
		}
		void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data) {
			return procs::pfnGlCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
		}
		void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data) {
			return procs::pfnGlCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
		}
		void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data) {
			return procs::pfnGlCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data);
		}
		void glGetCompressedTexImage(GLenum target, GLint level, void * img) {
			return procs::pfnGlGetCompressedTexImage(target, level, img);
		}
		void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
			return procs::pfnGlBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
		}
		void glMultiDrawArrays(GLenum mode, GLint * first, GLsizei * count, GLsizei drawcount) {
			return procs::pfnGlMultiDrawArrays(mode, first, count, drawcount);
		}
		void glMultiDrawElements(GLenum mode, GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount) {
			return procs::pfnGlMultiDrawElements(mode, count, type, indices, drawcount);
		}
		void glPointParameterf(GLenum pname, GLfloat param) {
			return procs::pfnGlPointParameterf(pname, param);
		}
		void glPointParameterfv(GLenum pname, GLfloat * params) {
			return procs::pfnGlPointParameterfv(pname, params);
		}
		void glPointParameteri(GLenum pname, GLint param) {
			return procs::pfnGlPointParameteri(pname, param);
		}
		void glPointParameteriv(GLenum pname, GLint * params) {
			return procs::pfnGlPointParameteriv(pname, params);
		}
		void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
			return procs::pfnGlBlendColor(red, green, blue, alpha);
		}
		void glBlendEquation(GLenum mode) {
			return procs::pfnGlBlendEquation(mode);
		}
		void glGenQueries(GLsizei n, GLuint * ids) {
			return procs::pfnGlGenQueries(n, ids);
		}
		void glDeleteQueries(GLsizei n, GLuint * ids) {
			return procs::pfnGlDeleteQueries(n, ids);
		}
		GLboolean glIsQuery(GLuint id) {
			return procs::pfnGlIsQuery(id);
		}
		void glBeginQuery(GLenum target, GLuint id) {
			return procs::pfnGlBeginQuery(target, id);
		}
		void glEndQuery(GLenum target) {
			return procs::pfnGlEndQuery(target);
		}
		void glGetQueryiv(GLenum target, GLenum pname, GLint * params) {
			return procs::pfnGlGetQueryiv(target, pname, params);
		}
		void glGetQueryObjectiv(GLuint id, GLenum pname, GLint * params) {
			return procs::pfnGlGetQueryObjectiv(id, pname, params);
		}
		void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint * params) {
			return procs::pfnGlGetQueryObjectuiv(id, pname, params);
		}
		void glBindBuffer(GLenum target, GLuint buffer) {
			return procs::pfnGlBindBuffer(target, buffer);
		}
		void glDeleteBuffers(GLsizei n, GLuint * buffers) {
			return procs::pfnGlDeleteBuffers(n, buffers);
		}
		void glGenBuffers(GLsizei n, GLuint * buffers) {
			return procs::pfnGlGenBuffers(n, buffers);
		}
		GLboolean glIsBuffer(GLuint buffer) {
			return procs::pfnGlIsBuffer(buffer);
		}
		void glBufferData(GLenum target, GLsizeiptr size, const void * data, GLenum usage) {
			return procs::pfnGlBufferData(target, size, data, usage);
		}
		void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void * data) {
			return procs::pfnGlBufferSubData(target, offset, size, data);
		}
		void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void * data) {
			return procs::pfnGlGetBufferSubData(target, offset, size, data);
		}
		void * glMapBuffer(GLenum target, GLenum access) {
			return procs::pfnGlMapBuffer(target, access);
		}
		GLboolean glUnmapBuffer(GLenum target) {
			return procs::pfnGlUnmapBuffer(target);
		}
		void glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params) {
			return procs::pfnGlGetBufferParameteriv(target, pname, params);
		}
		void glGetBufferPointerv(GLenum target, GLenum pname, void ** params) {
			return procs::pfnGlGetBufferPointerv(target, pname, params);
		}
		void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) {
			return procs::pfnGlBlendEquationSeparate(modeRGB, modeAlpha);
		}
		void glDrawBuffers(GLsizei n, GLenum * bufs) {
			return procs::pfnGlDrawBuffers(n, bufs);
		}
		void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) {
			return procs::pfnGlStencilOpSeparate(face, sfail, dpfail, dppass);
		}
		void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) {
			return procs::pfnGlStencilFuncSeparate(face, func, ref, mask);
		}
		void glStencilMaskSeparate(GLenum face, GLuint mask) {
			return procs::pfnGlStencilMaskSeparate(face, mask);
		}
		void glAttachShader(GLuint program, GLuint shader) {
			return procs::pfnGlAttachShader(program, shader);
		}
		void glBindAttribLocation(GLuint program, GLuint index, GLchar * name) {
			return procs::pfnGlBindAttribLocation(program, index, name);
		}
		void glCompileShader(GLuint shader) {
			return procs::pfnGlCompileShader(shader);
		}
		GLuint glCreateProgram() {
			return procs::pfnGlCreateProgram();
		}
		GLuint glCreateShader(GLenum type) {
			return procs::pfnGlCreateShader(type);
		}
		void glDeleteProgram(GLuint program) {
			return procs::pfnGlDeleteProgram(program);
		}
		void glDeleteShader(GLuint shader) {
			return procs::pfnGlDeleteShader(shader);
		}
		void glDetachShader(GLuint program, GLuint shader) {
			return procs::pfnGlDetachShader(program, shader);
		}
		void glDisableVertexAttribArray(GLuint index) {
			return procs::pfnGlDisableVertexAttribArray(index);
		}
		void glEnableVertexAttribArray(GLuint index) {
			return procs::pfnGlEnableVertexAttribArray(index);
		}
		void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) {
			return procs::pfnGlGetActiveAttrib(program, index, bufSize, length, size, type, name);
		}
		void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) {
			return procs::pfnGlGetActiveUniform(program, index, bufSize, length, size, type, name);
		}
		void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * shaders) {
			return procs::pfnGlGetAttachedShaders(program, maxCount, count, shaders);
		}
		GLint glGetAttribLocation(GLuint program, GLchar * name) {
			return procs::pfnGlGetAttribLocation(program, name);
		}
		void glGetProgramiv(GLuint program, GLenum pname, GLint * params) {
			return procs::pfnGlGetProgramiv(program, pname, params);
		}
		void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog) {
			return procs::pfnGlGetProgramInfoLog(program, bufSize, length, infoLog);
		}
		void glGetShaderiv(GLuint shader, GLenum pname, GLint * params) {
			return procs::pfnGlGetShaderiv(shader, pname, params);
		}
		void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog) {
			return procs::pfnGlGetShaderInfoLog(shader, bufSize, length, infoLog);
		}
		void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source) {
			return procs::pfnGlGetShaderSource(shader, bufSize, length, source);
		}
		GLint glGetUniformLocation(GLuint program, GLchar * name) {
			return procs::pfnGlGetUniformLocation(program, name);
		}
		void glGetUniformfv(GLuint program, GLint location, GLfloat * params) {
			return procs::pfnGlGetUniformfv(program, location, params);
		}
		void glGetUniformiv(GLuint program, GLint location, GLint * params) {
			return procs::pfnGlGetUniformiv(program, location, params);
		}
		void glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble * params) {
			return procs::pfnGlGetVertexAttribdv(index, pname, params);
		}
		void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat * params) {
			return procs::pfnGlGetVertexAttribfv(index, pname, params);
		}
		void glGetVertexAttribiv(GLuint index, GLenum pname, GLint * params) {
			return procs::pfnGlGetVertexAttribiv(index, pname, params);
		}
		void glGetVertexAttribPointerv(GLuint index, GLenum pname, void ** pointer) {
			return procs::pfnGlGetVertexAttribPointerv(index, pname, pointer);
		}
		GLboolean glIsProgram(GLuint program) {
			return procs::pfnGlIsProgram(program);
		}
		GLboolean glIsShader(GLuint shader) {
			return procs::pfnGlIsShader(shader);
		}
		void glLinkProgram(GLuint program) {
			return procs::pfnGlLinkProgram(program);
		}
		void glShaderSource(GLuint shader, GLsizei count, GLchar *const* string, GLint * length) {
			return procs::pfnGlShaderSource(shader, count, string, length);
		}
		void glUseProgram(GLuint program) {
			return procs::pfnGlUseProgram(program);
		}
		void glUniform1f(GLint location, GLfloat v0) {
			return procs::pfnGlUniform1f(location, v0);
		}
		void glUniform2f(GLint location, GLfloat v0, GLfloat v1) {
			return procs::pfnGlUniform2f(location, v0, v1);
		}
		void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
			return procs::pfnGlUniform3f(location, v0, v1, v2);
		}
		void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
			return procs::pfnGlUniform4f(location, v0, v1, v2, v3);
		}
		void glUniform1i(GLint location, GLint v0) {
			return procs::pfnGlUniform1i(location, v0);
		}
		void glUniform2i(GLint location, GLint v0, GLint v1) {
			return procs::pfnGlUniform2i(location, v0, v1);
		}
		void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) {
			return procs::pfnGlUniform3i(location, v0, v1, v2);
		}
		void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
			return procs::pfnGlUniform4i(location, v0, v1, v2, v3);
		}
		void glUniform1fv(GLint location, GLsizei count, GLfloat * value) {
			return procs::pfnGlUniform1fv(location, count, value);
		}
		void glUniform2fv(GLint location, GLsizei count, GLfloat * value) {
			return procs::pfnGlUniform2fv(location, count, value);
		}
		void glUniform3fv(GLint location, GLsizei count, GLfloat * value) {
			return procs::pfnGlUniform3fv(location, count, value);
		}
		void glUniform4fv(GLint location, GLsizei count, GLfloat * value) {
			return procs::pfnGlUniform4fv(location, count, value);
		}
		void glUniform1iv(GLint location, GLsizei count, GLint * value) {
			return procs::pfnGlUniform1iv(location, count, value);
		}
		void glUniform2iv(GLint location, GLsizei count, GLint * value) {
			return procs::pfnGlUniform2iv(location, count, value);
		}
		void glUniform3iv(GLint location, GLsizei count, GLint * value) {
			return procs::pfnGlUniform3iv(location, count, value);
		}
		void glUniform4iv(GLint location, GLsizei count, GLint * value) {
			return procs::pfnGlUniform4iv(location, count, value);
		}
		void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat * value) {
			return procs::pfnGlUniformMatrix2fv(location, count, transpose, value);
		}
		void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat * value) {
			return procs::pfnGlUniformMatrix3fv(location, count, transpose, value);
		}
		void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat * value) {
			return procs::pfnGlUniformMatrix4fv(location, count, transpose, value);
		}
		void glValidateProgram(GLuint program) {
			return procs::pfnGlValidateProgram(program);
		}
		void glVertexAttrib1d(GLuint index, GLdouble x) {
			return procs::pfnGlVertexAttrib1d(index, x);
		}
		void glVertexAttrib1dv(GLuint index, GLdouble * v) {
			return procs::pfnGlVertexAttrib1dv(index, v);
		}
		void glVertexAttrib1f(GLuint index, GLfloat x) {
			return procs::pfnGlVertexAttrib1f(index, x);
		}
		void glVertexAttrib1fv(GLuint index, GLfloat * v) {
			return procs::pfnGlVertexAttrib1fv(index, v);
		}
		void glVertexAttrib1s(GLuint index, GLshort x) {
			return procs::pfnGlVertexAttrib1s(index, x);
		}
		void glVertexAttrib1sv(GLuint index, GLshort * v) {
			return procs::pfnGlVertexAttrib1sv(index, v);
		}
		void glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y) {
			return procs::pfnGlVertexAttrib2d(index, x, y);
		}
		void glVertexAttrib2dv(GLuint index, GLdouble * v) {
			return procs::pfnGlVertexAttrib2dv(index, v);
		}
		void glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) {
			return procs::pfnGlVertexAttrib2f(index, x, y);
		}
		void glVertexAttrib2fv(GLuint index, GLfloat * v) {
			return procs::pfnGlVertexAttrib2fv(index, v);
		}
		void glVertexAttrib2s(GLuint index, GLshort x, GLshort y) {
			return procs::pfnGlVertexAttrib2s(index, x, y);
		}
		void glVertexAttrib2sv(GLuint index, GLshort * v) {
			return procs::pfnGlVertexAttrib2sv(index, v);
		}
		void glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) {
			return procs::pfnGlVertexAttrib3d(index, x, y, z);
		}
		void glVertexAttrib3dv(GLuint index, GLdouble * v) {
			return procs::pfnGlVertexAttrib3dv(index, v);
		}
		void glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) {
			return procs::pfnGlVertexAttrib3f(index, x, y, z);
		}
		void glVertexAttrib3fv(GLuint index, GLfloat * v) {
			return procs::pfnGlVertexAttrib3fv(index, v);
		}
		void glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z) {
			return procs::pfnGlVertexAttrib3s(index, x, y, z);
		}
		void glVertexAttrib3sv(GLuint index, GLshort * v) {
			return procs::pfnGlVertexAttrib3sv(index, v);
		}
		void glVertexAttrib4Nbv(GLuint index, GLbyte * v) {
			return procs::pfnGlVertexAttrib4Nbv(index, v);
		}
		void glVertexAttrib4Niv(GLuint index, GLint * v) {
			return procs::pfnGlVertexAttrib4Niv(index, v);
		}
		void glVertexAttrib4Nsv(GLuint index, GLshort * v) {
			return procs::pfnGlVertexAttrib4Nsv(index, v);
		}
		void glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) {
			return procs::pfnGlVertexAttrib4Nub(index, x, y, z, w);
		}
		void glVertexAttrib4Nubv(GLuint index, GLubyte * v) {
			return procs::pfnGlVertexAttrib4Nubv(index, v);
		}
		void glVertexAttrib4Nuiv(GLuint index, GLuint * v) {
			return procs::pfnGlVertexAttrib4Nuiv(index, v);
		}
		void glVertexAttrib4Nusv(GLuint index, GLushort * v) {
			return procs::pfnGlVertexAttrib4Nusv(index, v);
		}
		void glVertexAttrib4bv(GLuint index, GLbyte * v) {
			return procs::pfnGlVertexAttrib4bv(index, v);
		}
		void glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
			return procs::pfnGlVertexAttrib4d(index, x, y, z, w);
		}
		void glVertexAttrib4dv(GLuint index, GLdouble * v) {
			return procs::pfnGlVertexAttrib4dv(index, v);
		}
		void glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
			return procs::pfnGlVertexAttrib4f(index, x, y, z, w);
		}
		void glVertexAttrib4fv(GLuint index, GLfloat * v) {
			return procs::pfnGlVertexAttrib4fv(index, v);
		}
		void glVertexAttrib4iv(GLuint index, GLint * v) {
			return procs::pfnGlVertexAttrib4iv(index, v);
		}
		void glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) {
			return procs::pfnGlVertexAttrib4s(index, x, y, z, w);
		}
		void glVertexAttrib4sv(GLuint index, GLshort * v) {
			return procs::pfnGlVertexAttrib4sv(index, v);
		}
		void glVertexAttrib4ubv(GLuint index, GLubyte * v) {
			return procs::pfnGlVertexAttrib4ubv(index, v);
		}
		void glVertexAttrib4uiv(GLuint index, GLuint * v) {
			return procs::pfnGlVertexAttrib4uiv(index, v);
		}
		void glVertexAttrib4usv(GLuint index, GLushort * v) {
			return procs::pfnGlVertexAttrib4usv(index, v);
		}
		void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer) {
			return procs::pfnGlVertexAttribPointer(index, size, type, normalized, stride, pointer);
		}
		void glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat * value) {
			return procs::pfnGlUniformMatrix2x3fv(location, count, transpose, value);
		}
		void glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat * value) {
			return procs::pfnGlUniformMatrix3x2fv(location, count, transpose, value);
		}
		void glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat * value) {
			return procs::pfnGlUniformMatrix2x4fv(location, count, transpose, value);
		}
		void glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat * value) {
			return procs::pfnGlUniformMatrix4x2fv(location, count, transpose, value);
		}
		void glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat * value) {
			return procs::pfnGlUniformMatrix3x4fv(location, count, transpose, value);
		}
		void glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat * value) {
			return procs::pfnGlUniformMatrix4x3fv(location, count, transpose, value);
		}
		void glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) {
			return procs::pfnGlColorMaski(index, r, g, b, a);
		}
		void glGetBooleani_v(GLenum target, GLuint index, GLboolean * data) {
			return procs::pfnGlGetBooleani_v(target, index, data);
		}
		void glGetIntegeri_v(GLenum target, GLuint index, GLint * data) {
			return procs::pfnGlGetIntegeri_v(target, index, data);
		}
		void glEnablei(GLenum target, GLuint index) {
			return procs::pfnGlEnablei(target, index);
		}
		void glDisablei(GLenum target, GLuint index) {
			return procs::pfnGlDisablei(target, index);
		}
		GLboolean glIsEnabledi(GLenum target, GLuint index) {
			return procs::pfnGlIsEnabledi(target, index);
		}
		void glBeginTransformFeedback(GLenum primitiveMode) {
			return procs::pfnGlBeginTransformFeedback(primitiveMode);
		}
		void glEndTransformFeedback() {
			return procs::pfnGlEndTransformFeedback();
		}
		void glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) {
			return procs::pfnGlBindBufferRange(target, index, buffer, offset, size);
		}
		void glBindBufferBase(GLenum target, GLuint index, GLuint buffer) {
			return procs::pfnGlBindBufferBase(target, index, buffer);
		}
		void glTransformFeedbackVaryings(GLuint program, GLsizei count, GLchar *const* varyings, GLenum bufferMode) {
			return procs::pfnGlTransformFeedbackVaryings(program, count, varyings, bufferMode);
		}
		void glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name) {
			return procs::pfnGlGetTransformFeedbackVarying(program, index, bufSize, length, size, type, name);
		}
		void glClampColor(GLenum target, GLenum clamp) {
			return procs::pfnGlClampColor(target, clamp);
		}
		void glBeginConditionalRender(GLuint id, GLenum mode) {
			return procs::pfnGlBeginConditionalRender(id, mode);
		}
		void glEndConditionalRender() {
			return procs::pfnGlEndConditionalRender();
		}
		void glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer) {
			return procs::pfnGlVertexAttribIPointer(index, size, type, stride, pointer);
		}
		void glGetVertexAttribIiv(GLuint index, GLenum pname, GLint * params) {
			return procs::pfnGlGetVertexAttribIiv(index, pname, params);
		}
		void glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint * params) {
			return procs::pfnGlGetVertexAttribIuiv(index, pname, params);
		}
		void glVertexAttribI1i(GLuint index, GLint x) {
			return procs::pfnGlVertexAttribI1i(index, x);
		}
		void glVertexAttribI2i(GLuint index, GLint x, GLint y) {
			return procs::pfnGlVertexAttribI2i(index, x, y);
		}
		void glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z) {
			return procs::pfnGlVertexAttribI3i(index, x, y, z);
		}
		void glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w) {
			return procs::pfnGlVertexAttribI4i(index, x, y, z, w);
		}
		void glVertexAttribI1ui(GLuint index, GLuint x) {
			return procs::pfnGlVertexAttribI1ui(index, x);
		}
		void glVertexAttribI2ui(GLuint index, GLuint x, GLuint y) {
			return procs::pfnGlVertexAttribI2ui(index, x, y);
		}
		void glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z) {
			return procs::pfnGlVertexAttribI3ui(index, x, y, z);
		}
		void glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) {
			return procs::pfnGlVertexAttribI4ui(index, x, y, z, w);
		}
		void glVertexAttribI1iv(GLuint index, GLint * v) {
			return procs::pfnGlVertexAttribI1iv(index, v);
		}
		void glVertexAttribI2iv(GLuint index, GLint * v) {
			return procs::pfnGlVertexAttribI2iv(index, v);
		}
		void glVertexAttribI3iv(GLuint index, GLint * v) {
			return procs::pfnGlVertexAttribI3iv(index, v);
		}
		void glVertexAttribI4iv(GLuint index, GLint * v) {
			return procs::pfnGlVertexAttribI4iv(index, v);
		}
		void glVertexAttribI1uiv(GLuint index, GLuint * v) {
			return procs::pfnGlVertexAttribI1uiv(index, v);
		}
		void glVertexAttribI2uiv(GLuint index, GLuint * v) {
			return procs::pfnGlVertexAttribI2uiv(index, v);
		}
		void glVertexAttribI3uiv(GLuint index, GLuint * v) {
			return procs::pfnGlVertexAttribI3uiv(index, v);
		}
		void glVertexAttribI4uiv(GLuint index, GLuint * v) {
			return procs::pfnGlVertexAttribI4uiv(index, v);
		}
		void glVertexAttribI4bv(GLuint index, GLbyte * v) {
			return procs::pfnGlVertexAttribI4bv(index, v);
		}
		void glVertexAttribI4sv(GLuint index, GLshort * v) {
			return procs::pfnGlVertexAttribI4sv(index, v);
		}
		void glVertexAttribI4ubv(GLuint index, GLubyte * v) {
			return procs::pfnGlVertexAttribI4ubv(index, v);
		}
		void glVertexAttribI4usv(GLuint index, GLushort * v) {
			return procs::pfnGlVertexAttribI4usv(index, v);
		}
		void glGetUniformuiv(GLuint program, GLint location, GLuint * params) {
			return procs::pfnGlGetUniformuiv(program, location, params);
		}
		void glBindFragDataLocation(GLuint program, GLuint color, GLchar * name) {
			return procs::pfnGlBindFragDataLocation(program, color, name);
		}
		GLint glGetFragDataLocation(GLuint program, GLchar * name) {
			return procs::pfnGlGetFragDataLocation(program, name);
		}
		void glUniform1ui(GLint location, GLuint v0) {
			return procs::pfnGlUniform1ui(location, v0);
		}
		void glUniform2ui(GLint location, GLuint v0, GLuint v1) {
			return procs::pfnGlUniform2ui(location, v0, v1);
		}
		void glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2) {
			return procs::pfnGlUniform3ui(location, v0, v1, v2);
		}
		void glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
			return procs::pfnGlUniform4ui(location, v0, v1, v2, v3);
		}
		void glUniform1uiv(GLint location, GLsizei count, GLuint * value) {
			return procs::pfnGlUniform1uiv(location, count, value);
		}
		void glUniform2uiv(GLint location, GLsizei count, GLuint * value) {
			return procs::pfnGlUniform2uiv(location, count, value);
		}
		void glUniform3uiv(GLint location, GLsizei count, GLuint * value) {
			return procs::pfnGlUniform3uiv(location, count, value);
		}
		void glUniform4uiv(GLint location, GLsizei count, GLuint * value) {
			return procs::pfnGlUniform4uiv(location, count, value);
		}
		void glTexParameterIiv(GLenum target, GLenum pname, GLint * params) {
			return procs::pfnGlTexParameterIiv(target, pname, params);
		}
		void glTexParameterIuiv(GLenum target, GLenum pname, GLuint * params) {
			return procs::pfnGlTexParameterIuiv(target, pname, params);
		}
		void glGetTexParameterIiv(GLenum target, GLenum pname, GLint * params) {
			return procs::pfnGlGetTexParameterIiv(target, pname, params);
		}
		void glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint * params) {
			return procs::pfnGlGetTexParameterIuiv(target, pname, params);
		}
		void glClearBufferiv(GLenum buffer, GLint drawbuffer, GLint * value) {
			return procs::pfnGlClearBufferiv(buffer, drawbuffer, value);
		}
		void glClearBufferuiv(GLenum buffer, GLint drawbuffer, GLuint * value) {
			return procs::pfnGlClearBufferuiv(buffer, drawbuffer, value);
		}
		void glClearBufferfv(GLenum buffer, GLint drawbuffer, GLfloat * value) {
			return procs::pfnGlClearBufferfv(buffer, drawbuffer, value);
		}
		void glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) {
			return procs::pfnGlClearBufferfi(buffer, drawbuffer, depth, stencil);
		}
		GLubyte * glGetStringi(GLenum name, GLuint index) {
			return procs::pfnGlGetStringi(name, index);
		}
		GLboolean glIsRenderbuffer(GLuint renderbuffer) {
			return procs::pfnGlIsRenderbuffer(renderbuffer);
		}
		void glBindRenderbuffer(GLenum target, GLuint renderbuffer) {
			return procs::pfnGlBindRenderbuffer(target, renderbuffer);
		}
		void glDeleteRenderbuffers(GLsizei n, GLuint * renderbuffers) {
			return procs::pfnGlDeleteRenderbuffers(n, renderbuffers);
		}
		void glGenRenderbuffers(GLsizei n, GLuint * renderbuffers) {
			return procs::pfnGlGenRenderbuffers(n, renderbuffers);
		}
		void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
			return procs::pfnGlRenderbufferStorage(target, internalformat, width, height);
		}
		void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params) {
			return procs::pfnGlGetRenderbufferParameteriv(target, pname, params);
		}
		GLboolean glIsFramebuffer(GLuint framebuffer) {
			return procs::pfnGlIsFramebuffer(framebuffer);
		}
		void glBindFramebuffer(GLenum target, GLuint framebuffer) {
			return procs::pfnGlBindFramebuffer(target, framebuffer);
		}
		void glDeleteFramebuffers(GLsizei n, GLuint * framebuffers) {
			return procs::pfnGlDeleteFramebuffers(n, framebuffers);
		}
		void glGenFramebuffers(GLsizei n, GLuint * framebuffers) {
			return procs::pfnGlGenFramebuffers(n, framebuffers);
		}
		GLenum glCheckFramebufferStatus(GLenum target) {
			return procs::pfnGlCheckFramebufferStatus(target);
		}
		void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
			return procs::pfnGlFramebufferTexture1D(target, attachment, textarget, texture, level);
		}
		void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
			return procs::pfnGlFramebufferTexture2D(target, attachment, textarget, texture, level);
		}
		void glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) {
			return procs::pfnGlFramebufferTexture3D(target, attachment, textarget, texture, level, zoffset);
		}
		void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
			return procs::pfnGlFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
		}
		void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint * params) {
			return procs::pfnGlGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
		}
		void glGenerateMipmap(GLenum target) {
			return procs::pfnGlGenerateMipmap(target);
		}
		void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {
			return procs::pfnGlBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
		}
		void glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {
			return procs::pfnGlRenderbufferStorageMultisample(target, samples, internalformat, width, height);
		}
		void glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) {
			return procs::pfnGlFramebufferTextureLayer(target, attachment, texture, level, layer);
		}
		void * glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) {
			return procs::pfnGlMapBufferRange(target, offset, length, access);
		}
		void glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length) {
			return procs::pfnGlFlushMappedBufferRange(target, offset, length);
		}
		void glBindVertexArray(GLuint array) {
			return procs::pfnGlBindVertexArray(array);
		}
		void glDeleteVertexArrays(GLsizei n, GLuint * arrays) {
			return procs::pfnGlDeleteVertexArrays(n, arrays);
		}
		void glGenVertexArrays(GLsizei n, GLuint * arrays) {
			return procs::pfnGlGenVertexArrays(n, arrays);
		}
		GLboolean glIsVertexArray(GLuint array) {
			return procs::pfnGlIsVertexArray(array);
		}
		void glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount) {
			return procs::pfnGlDrawArraysInstanced(mode, first, count, instancecount);
		}
		void glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount) {
			return procs::pfnGlDrawElementsInstanced(mode, count, type, indices, instancecount);
		}
		void glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer) {
			return procs::pfnGlTexBuffer(target, internalformat, buffer);
		}
		void glPrimitiveRestartIndex(GLuint index) {
			return procs::pfnGlPrimitiveRestartIndex(index);
		}
		void glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) {
			return procs::pfnGlCopyBufferSubData(readTarget, writeTarget, readOffset, writeOffset, size);
		}
		void glGetUniformIndices(GLuint program, GLsizei uniformCount, GLchar *const* uniformNames, GLuint * uniformIndices) {
			return procs::pfnGlGetUniformIndices(program, uniformCount, uniformNames, uniformIndices);
		}
		void glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, GLuint * uniformIndices, GLenum pname, GLint * params) {
			return procs::pfnGlGetActiveUniformsiv(program, uniformCount, uniformIndices, pname, params);
		}
		void glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformName) {
			return procs::pfnGlGetActiveUniformName(program, uniformIndex, bufSize, length, uniformName);
		}
		GLuint glGetUniformBlockIndex(GLuint program, GLchar * uniformBlockName) {
			return procs::pfnGlGetUniformBlockIndex(program, uniformBlockName);
		}
		void glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint * params) {
			return procs::pfnGlGetActiveUniformBlockiv(program, uniformBlockIndex, pname, params);
		}
		void glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformBlockName) {
			return procs::pfnGlGetActiveUniformBlockName(program, uniformBlockIndex, bufSize, length, uniformBlockName);
		}
		void glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) {
			return procs::pfnGlUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding);
		}
		void glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex) {
			return procs::pfnGlDrawElementsBaseVertex(mode, count, type, indices, basevertex);
		}
		void glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex) {
			return procs::pfnGlDrawRangeElementsBaseVertex(mode, start, end, count, type, indices, basevertex);
		}
		void glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex) {
			return procs::pfnGlDrawElementsInstancedBaseVertex(mode, count, type, indices, instancecount, basevertex);
		}
		void glMultiDrawElementsBaseVertex(GLenum mode, GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount, GLint * basevertex) {
			return procs::pfnGlMultiDrawElementsBaseVertex(mode, count, type, indices, drawcount, basevertex);
		}
		void glProvokingVertex(GLenum mode) {
			return procs::pfnGlProvokingVertex(mode);
		}
		GLsync glFenceSync(GLenum condition, GLbitfield flags) {
			return procs::pfnGlFenceSync(condition, flags);
		}
		GLboolean glIsSync(GLsync sync) {
			return procs::pfnGlIsSync(sync);
		}
		void glDeleteSync(GLsync sync) {
			return procs::pfnGlDeleteSync(sync);
		}
		GLenum glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) {
			return procs::pfnGlClientWaitSync(sync, flags, timeout);
		}
		void glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) {
			return procs::pfnGlWaitSync(sync, flags, timeout);
		}
		void glGetInteger64v(GLenum pname, GLint64 * data) {
			return procs::pfnGlGetInteger64v(pname, data);
		}
		void glGetSynciv(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei * length, GLint * values) {
			return procs::pfnGlGetSynciv(sync, pname, bufSize, length, values);
		}
		void glGetInteger64i_v(GLenum target, GLuint index, GLint64 * data) {
			return procs::pfnGlGetInteger64i_v(target, index, data);
		}
		void glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64 * params) {
			return procs::pfnGlGetBufferParameteri64v(target, pname, params);
		}
		void glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level) {
			return procs::pfnGlFramebufferTexture(target, attachment, texture, level);
		}
		void glTexImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) {
			return procs::pfnGlTexImage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations);
		}
		void glTexImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {
			return procs::pfnGlTexImage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations);
		}
		void glGetMultisamplefv(GLenum pname, GLuint index, GLfloat * val) {
			return procs::pfnGlGetMultisamplefv(pname, index, val);
		}
		void glSampleMaski(GLuint maskNumber, GLbitfield mask) {
			return procs::pfnGlSampleMaski(maskNumber, mask);
		}
		void glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, GLchar * name) {
			return procs::pfnGlBindFragDataLocationIndexed(program, colorNumber, index, name);
		}
		GLint glGetFragDataIndex(GLuint program, GLchar * name) {
			return procs::pfnGlGetFragDataIndex(program, name);
		}
		void glGenSamplers(GLsizei count, GLuint * samplers) {
			return procs::pfnGlGenSamplers(count, samplers);
		}
		void glDeleteSamplers(GLsizei count, GLuint * samplers) {
			return procs::pfnGlDeleteSamplers(count, samplers);
		}
		GLboolean glIsSampler(GLuint sampler) {
			return procs::pfnGlIsSampler(sampler);
		}
		void glBindSampler(GLuint unit, GLuint sampler) {
			return procs::pfnGlBindSampler(unit, sampler);
		}
		void glSamplerParameteri(GLuint sampler, GLenum pname, GLint param) {
			return procs::pfnGlSamplerParameteri(sampler, pname, param);
		}
		void glSamplerParameteriv(GLuint sampler, GLenum pname, GLint * param) {
			return procs::pfnGlSamplerParameteriv(sampler, pname, param);
		}
		void glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param) {
			return procs::pfnGlSamplerParameterf(sampler, pname, param);
		}
		void glSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat * param) {
			return procs::pfnGlSamplerParameterfv(sampler, pname, param);
		}
		void glSamplerParameterIiv(GLuint sampler, GLenum pname, GLint * param) {
			return procs::pfnGlSamplerParameterIiv(sampler, pname, param);
		}
		void glSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint * param) {
			return procs::pfnGlSamplerParameterIuiv(sampler, pname, param);
		}
		void glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint * params) {
			return procs::pfnGlGetSamplerParameteriv(sampler, pname, params);
		}
		void glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint * params) {
			return procs::pfnGlGetSamplerParameterIiv(sampler, pname, params);
		}
		void glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat * params) {
			return procs::pfnGlGetSamplerParameterfv(sampler, pname, params);
		}
		void glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint * params) {
			return procs::pfnGlGetSamplerParameterIuiv(sampler, pname, params);
		}
		void glQueryCounter(GLuint id, GLenum target) {
			return procs::pfnGlQueryCounter(id, target);
		}
		void glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64 * params) {
			return procs::pfnGlGetQueryObjecti64v(id, pname, params);
		}
		void glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 * params) {
			return procs::pfnGlGetQueryObjectui64v(id, pname, params);
		}
		void glVertexAttribDivisor(GLuint index, GLuint divisor) {
			return procs::pfnGlVertexAttribDivisor(index, divisor);
		}
		void glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
			return procs::pfnGlVertexAttribP1ui(index, type, normalized, value);
		}
		void glVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, GLuint * value) {
			return procs::pfnGlVertexAttribP1uiv(index, type, normalized, value);
		}
		void glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
			return procs::pfnGlVertexAttribP2ui(index, type, normalized, value);
		}
		void glVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, GLuint * value) {
			return procs::pfnGlVertexAttribP2uiv(index, type, normalized, value);
		}
		void glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
			return procs::pfnGlVertexAttribP3ui(index, type, normalized, value);
		}
		void glVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, GLuint * value) {
			return procs::pfnGlVertexAttribP3uiv(index, type, normalized, value);
		}
		void glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
			return procs::pfnGlVertexAttribP4ui(index, type, normalized, value);
		}
		void glVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, GLuint * value) {
			return procs::pfnGlVertexAttribP4uiv(index, type, normalized, value);
		}
		void glVertexP2ui(GLenum type, GLuint value) {
			return procs::pfnGlVertexP2ui(type, value);
		}
		void glVertexP2uiv(GLenum type, GLuint * value) {
			return procs::pfnGlVertexP2uiv(type, value);
		}
		void glVertexP3ui(GLenum type, GLuint value) {
			return procs::pfnGlVertexP3ui(type, value);
		}
		void glVertexP3uiv(GLenum type, GLuint * value) {
			return procs::pfnGlVertexP3uiv(type, value);
		}
		void glVertexP4ui(GLenum type, GLuint value) {
			return procs::pfnGlVertexP4ui(type, value);
		}
		void glVertexP4uiv(GLenum type, GLuint * value) {
			return procs::pfnGlVertexP4uiv(type, value);
		}
		void glTexCoordP1ui(GLenum type, GLuint coords) {
			return procs::pfnGlTexCoordP1ui(type, coords);
		}
		void glTexCoordP1uiv(GLenum type, GLuint * coords) {
			return procs::pfnGlTexCoordP1uiv(type, coords);
		}
		void glTexCoordP2ui(GLenum type, GLuint coords) {
			return procs::pfnGlTexCoordP2ui(type, coords);
		}
		void glTexCoordP2uiv(GLenum type, GLuint * coords) {
			return procs::pfnGlTexCoordP2uiv(type, coords);
		}
		void glTexCoordP3ui(GLenum type, GLuint coords) {
			return procs::pfnGlTexCoordP3ui(type, coords);
		}
		void glTexCoordP3uiv(GLenum type, GLuint * coords) {
			return procs::pfnGlTexCoordP3uiv(type, coords);
		}
		void glTexCoordP4ui(GLenum type, GLuint coords) {
			return procs::pfnGlTexCoordP4ui(type, coords);
		}
		void glTexCoordP4uiv(GLenum type, GLuint * coords) {
			return procs::pfnGlTexCoordP4uiv(type, coords);
		}
		void glMultiTexCoordP1ui(GLenum texture, GLenum type, GLuint coords) {
			return procs::pfnGlMultiTexCoordP1ui(texture, type, coords);
		}
		void glMultiTexCoordP1uiv(GLenum texture, GLenum type, GLuint * coords) {
			return procs::pfnGlMultiTexCoordP1uiv(texture, type, coords);
		}
		void glMultiTexCoordP2ui(GLenum texture, GLenum type, GLuint coords) {
			return procs::pfnGlMultiTexCoordP2ui(texture, type, coords);
		}
		void glMultiTexCoordP2uiv(GLenum texture, GLenum type, GLuint * coords) {
			return procs::pfnGlMultiTexCoordP2uiv(texture, type, coords);
		}
		void glMultiTexCoordP3ui(GLenum texture, GLenum type, GLuint coords) {
			return procs::pfnGlMultiTexCoordP3ui(texture, type, coords);
		}
		void glMultiTexCoordP3uiv(GLenum texture, GLenum type, GLuint * coords) {
			return procs::pfnGlMultiTexCoordP3uiv(texture, type, coords);
		}
		void glMultiTexCoordP4ui(GLenum texture, GLenum type, GLuint coords) {
			return procs::pfnGlMultiTexCoordP4ui(texture, type, coords);
		}
		void glMultiTexCoordP4uiv(GLenum texture, GLenum type, GLuint * coords) {
			return procs::pfnGlMultiTexCoordP4uiv(texture, type, coords);
		}
		void glNormalP3ui(GLenum type, GLuint coords) {
			return procs::pfnGlNormalP3ui(type, coords);
		}
		void glNormalP3uiv(GLenum type, GLuint * coords) {
			return procs::pfnGlNormalP3uiv(type, coords);
		}
		void glColorP3ui(GLenum type, GLuint color) {
			return procs::pfnGlColorP3ui(type, color);
		}
		void glColorP3uiv(GLenum type, GLuint * color) {
			return procs::pfnGlColorP3uiv(type, color);
		}
		void glColorP4ui(GLenum type, GLuint color) {
			return procs::pfnGlColorP4ui(type, color);
		}
		void glColorP4uiv(GLenum type, GLuint * color) {
			return procs::pfnGlColorP4uiv(type, color);
		}
		void glSecondaryColorP3ui(GLenum type, GLuint color) {
			return procs::pfnGlSecondaryColorP3ui(type, color);
		}
		void glSecondaryColorP3uiv(GLenum type, GLuint * color) {
			return procs::pfnGlSecondaryColorP3uiv(type, color);
		}
		void glMinSampleShading(GLfloat value) {
			return procs::pfnGlMinSampleShading(value);
		}
		void glBlendEquationi(GLuint buf, GLenum mode) {
			return procs::pfnGlBlendEquationi(buf, mode);
		}
		void glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha) {
			return procs::pfnGlBlendEquationSeparatei(buf, modeRGB, modeAlpha);
		}
		void glBlendFunci(GLuint buf, GLenum src, GLenum dst) {
			return procs::pfnGlBlendFunci(buf, src, dst);
		}
		void glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
			return procs::pfnGlBlendFuncSeparatei(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
		}
		void glDrawArraysIndirect(GLenum mode, const void * indirect) {
			return procs::pfnGlDrawArraysIndirect(mode, indirect);
		}
		void glDrawElementsIndirect(GLenum mode, GLenum type, const void * indirect) {
			return procs::pfnGlDrawElementsIndirect(mode, type, indirect);
		}
		void glUniform1d(GLint location, GLdouble x) {
			return procs::pfnGlUniform1d(location, x);
		}
		void glUniform2d(GLint location, GLdouble x, GLdouble y) {
			return procs::pfnGlUniform2d(location, x, y);
		}
		void glUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z) {
			return procs::pfnGlUniform3d(location, x, y, z);
		}
		void glUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
			return procs::pfnGlUniform4d(location, x, y, z, w);
		}
		void glUniform1dv(GLint location, GLsizei count, GLdouble * value) {
			return procs::pfnGlUniform1dv(location, count, value);
		}
		void glUniform2dv(GLint location, GLsizei count, GLdouble * value) {
			return procs::pfnGlUniform2dv(location, count, value);
		}
		void glUniform3dv(GLint location, GLsizei count, GLdouble * value) {
			return procs::pfnGlUniform3dv(location, count, value);
		}
		void glUniform4dv(GLint location, GLsizei count, GLdouble * value) {
			return procs::pfnGlUniform4dv(location, count, value);
		}
		void glUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, GLdouble * value) {
			return procs::pfnGlUniformMatrix2dv(location, count, transpose, value);
		}
		void glUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, GLdouble * value) {
			return procs::pfnGlUniformMatrix3dv(location, count, transpose, value);
		}
		void glUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, GLdouble * value) {
			return procs::pfnGlUniformMatrix4dv(location, count, transpose, value);
		}
		void glUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, GLdouble * value) {
			return procs::pfnGlUniformMatrix2x3dv(location, count, transpose, value);
		}
		void glUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, GLdouble * value) {
			return procs::pfnGlUniformMatrix2x4dv(location, count, transpose, value);
		}
		void glUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, GLdouble * value) {
			return procs::pfnGlUniformMatrix3x2dv(location, count, transpose, value);
		}
		void glUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, GLdouble * value) {
			return procs::pfnGlUniformMatrix3x4dv(location, count, transpose, value);
		}
		void glUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, GLdouble * value) {
			return procs::pfnGlUniformMatrix4x2dv(location, count, transpose, value);
		}
		void glUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, GLdouble * value) {
			return procs::pfnGlUniformMatrix4x3dv(location, count, transpose, value);
		}
		void glGetUniformdv(GLuint program, GLint location, GLdouble * params) {
			return procs::pfnGlGetUniformdv(program, location, params);
		}
		GLint glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, GLchar * name) {
			return procs::pfnGlGetSubroutineUniformLocation(program, shadertype, name);
		}
		GLuint glGetSubroutineIndex(GLuint program, GLenum shadertype, GLchar * name) {
			return procs::pfnGlGetSubroutineIndex(program, shadertype, name);
		}
		void glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint * values) {
			return procs::pfnGlGetActiveSubroutineUniformiv(program, shadertype, index, pname, values);
		}
		void glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei * length, GLchar * name) {
			return procs::pfnGlGetActiveSubroutineUniformName(program, shadertype, index, bufsize, length, name);
		}
		void glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei * length, GLchar * name) {
			return procs::pfnGlGetActiveSubroutineName(program, shadertype, index, bufsize, length, name);
		}
		void glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, GLuint * indices) {
			return procs::pfnGlUniformSubroutinesuiv(shadertype, count, indices);
		}
		void glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint * params) {
			return procs::pfnGlGetUniformSubroutineuiv(shadertype, location, params);
		}
		void glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint * values) {
			return procs::pfnGlGetProgramStageiv(program, shadertype, pname, values);
		}
		void glPatchParameteri(GLenum pname, GLint value) {
			return procs::pfnGlPatchParameteri(pname, value);
		}
		void glPatchParameterfv(GLenum pname, GLfloat * values) {
			return procs::pfnGlPatchParameterfv(pname, values);
		}
		void glBindTransformFeedback(GLenum target, GLuint id) {
			return procs::pfnGlBindTransformFeedback(target, id);
		}
		void glDeleteTransformFeedbacks(GLsizei n, GLuint * ids) {
			return procs::pfnGlDeleteTransformFeedbacks(n, ids);
		}
		void glGenTransformFeedbacks(GLsizei n, GLuint * ids) {
			return procs::pfnGlGenTransformFeedbacks(n, ids);
		}
		GLboolean glIsTransformFeedback(GLuint id) {
			return procs::pfnGlIsTransformFeedback(id);
		}
		void glPauseTransformFeedback() {
			return procs::pfnGlPauseTransformFeedback();
		}
		void glResumeTransformFeedback() {
			return procs::pfnGlResumeTransformFeedback();
		}
		void glDrawTransformFeedback(GLenum mode, GLuint id) {
			return procs::pfnGlDrawTransformFeedback(mode, id);
		}
		void glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream) {
			return procs::pfnGlDrawTransformFeedbackStream(mode, id, stream);
		}
		void glBeginQueryIndexed(GLenum target, GLuint index, GLuint id) {
			return procs::pfnGlBeginQueryIndexed(target, index, id);
		}
		void glEndQueryIndexed(GLenum target, GLuint index) {
			return procs::pfnGlEndQueryIndexed(target, index);
		}
		void glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint * params) {
			return procs::pfnGlGetQueryIndexediv(target, index, pname, params);
		}
		void glReleaseShaderCompiler() {
			return procs::pfnGlReleaseShaderCompiler();
		}
		void glShaderBinary(GLsizei count, GLuint * shaders, GLenum binaryformat, const void * binary, GLsizei length) {
			return procs::pfnGlShaderBinary(count, shaders, binaryformat, binary, length);
		}
		void glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision) {
			return procs::pfnGlGetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
		}
		void glDepthRangef(GLfloat n, GLfloat f) {
			return procs::pfnGlDepthRangef(n, f);
		}
		void glClearDepthf(GLfloat d) {
			return procs::pfnGlClearDepthf(d);
		}
		void glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei * length, GLenum * binaryFormat, void * binary) {
			return procs::pfnGlGetProgramBinary(program, bufSize, length, binaryFormat, binary);
		}
		void glProgramBinary(GLuint program, GLenum binaryFormat, const void * binary, GLsizei length) {
			return procs::pfnGlProgramBinary(program, binaryFormat, binary, length);
		}
		void glProgramParameteri(GLuint program, GLenum pname, GLint value) {
			return procs::pfnGlProgramParameteri(program, pname, value);
		}
		void glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program) {
			return procs::pfnGlUseProgramStages(pipeline, stages, program);
		}
		void glActiveShaderProgram(GLuint pipeline, GLuint program) {
			return procs::pfnGlActiveShaderProgram(pipeline, program);
		}
		GLuint glCreateShaderProgramv(GLenum type, GLsizei count, GLchar *const* strings) {
			return procs::pfnGlCreateShaderProgramv(type, count, strings);
		}
		void glBindProgramPipeline(GLuint pipeline) {
			return procs::pfnGlBindProgramPipeline(pipeline);
		}
		void glDeleteProgramPipelines(GLsizei n, GLuint * pipelines) {
			return procs::pfnGlDeleteProgramPipelines(n, pipelines);
		}
		void glGenProgramPipelines(GLsizei n, GLuint * pipelines) {
			return procs::pfnGlGenProgramPipelines(n, pipelines);
		}
		GLboolean glIsProgramPipeline(GLuint pipeline) {
			return procs::pfnGlIsProgramPipeline(pipeline);
		}
		void glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint * params) {
			return procs::pfnGlGetProgramPipelineiv(pipeline, pname, params);
		}
		void glProgramUniform1i(GLuint program, GLint location, GLint v0) {
			return procs::pfnGlProgramUniform1i(program, location, v0);
		}
		void glProgramUniform1iv(GLuint program, GLint location, GLsizei count, GLint * value) {
			return procs::pfnGlProgramUniform1iv(program, location, count, value);
		}
		void glProgramUniform1f(GLuint program, GLint location, GLfloat v0) {
			return procs::pfnGlProgramUniform1f(program, location, v0);
		}
		void glProgramUniform1fv(GLuint program, GLint location, GLsizei count, GLfloat * value) {
			return procs::pfnGlProgramUniform1fv(program, location, count, value);
		}
		void glProgramUniform1d(GLuint program, GLint location, GLdouble v0) {
			return procs::pfnGlProgramUniform1d(program, location, v0);
		}
		void glProgramUniform1dv(GLuint program, GLint location, GLsizei count, GLdouble * value) {
			return procs::pfnGlProgramUniform1dv(program, location, count, value);
		}
		void glProgramUniform1ui(GLuint program, GLint location, GLuint v0) {
			return procs::pfnGlProgramUniform1ui(program, location, v0);
		}
		void glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, GLuint * value) {
			return procs::pfnGlProgramUniform1uiv(program, location, count, value);
		}
		void glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1) {
			return procs::pfnGlProgramUniform2i(program, location, v0, v1);
		}
		void glProgramUniform2iv(GLuint program, GLint location, GLsizei count, GLint * value) {
			return procs::pfnGlProgramUniform2iv(program, location, count, value);
		}
		void glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1) {
			return procs::pfnGlProgramUniform2f(program, location, v0, v1);
		}
		void glProgramUniform2fv(GLuint program, GLint location, GLsizei count, GLfloat * value) {
			return procs::pfnGlProgramUniform2fv(program, location, count, value);
		}
		void glProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1) {
			return procs::pfnGlProgramUniform2d(program, location, v0, v1);
		}
		void glProgramUniform2dv(GLuint program, GLint location, GLsizei count, GLdouble * value) {
			return procs::pfnGlProgramUniform2dv(program, location, count, value);
		}
		void glProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1) {
			return procs::pfnGlProgramUniform2ui(program, location, v0, v1);
		}
		void glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, GLuint * value) {
			return procs::pfnGlProgramUniform2uiv(program, location, count, value);
		}
		void glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) {
			return procs::pfnGlProgramUniform3i(program, location, v0, v1, v2);
		}
		void glProgramUniform3iv(GLuint program, GLint location, GLsizei count, GLint * value) {
			return procs::pfnGlProgramUniform3iv(program, location, count, value);
		}
		void glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
			return procs::pfnGlProgramUniform3f(program, location, v0, v1, v2);
		}
		void glProgramUniform3fv(GLuint program, GLint location, GLsizei count, GLfloat * value) {
			return procs::pfnGlProgramUniform3fv(program, location, count, value);
		}
		void glProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2) {
			return procs::pfnGlProgramUniform3d(program, location, v0, v1, v2);
		}
		void glProgramUniform3dv(GLuint program, GLint location, GLsizei count, GLdouble * value) {
			return procs::pfnGlProgramUniform3dv(program, location, count, value);
		}
		void glProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) {
			return procs::pfnGlProgramUniform3ui(program, location, v0, v1, v2);
		}
		void glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, GLuint * value) {
			return procs::pfnGlProgramUniform3uiv(program, location, count, value);
		}
		void glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
			return procs::pfnGlProgramUniform4i(program, location, v0, v1, v2, v3);
		}
		void glProgramUniform4iv(GLuint program, GLint location, GLsizei count, GLint * value) {
			return procs::pfnGlProgramUniform4iv(program, location, count, value);
		}
		void glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
			return procs::pfnGlProgramUniform4f(program, location, v0, v1, v2, v3);
		}
		void glProgramUniform4fv(GLuint program, GLint location, GLsizei count, GLfloat * value) {
			return procs::pfnGlProgramUniform4fv(program, location, count, value);
		}
		void glProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3) {
			return procs::pfnGlProgramUniform4d(program, location, v0, v1, v2, v3);
		}
		void glProgramUniform4dv(GLuint program, GLint location, GLsizei count, GLdouble * value) {
			return procs::pfnGlProgramUniform4dv(program, location, count, value);
		}
		void glProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
			return procs::pfnGlProgramUniform4ui(program, location, v0, v1, v2, v3);
		}
		void glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, GLuint * value) {
			return procs::pfnGlProgramUniform4uiv(program, location, count, value);
		}
		void glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat * value) {
			return procs::pfnGlProgramUniformMatrix2fv(program, location, count, transpose, value);
		}
		void glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat * value) {
			return procs::pfnGlProgramUniformMatrix3fv(program, location, count, transpose, value);
		}
		void glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat * value) {
			return procs::pfnGlProgramUniformMatrix4fv(program, location, count, transpose, value);
		}
		void glProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble * value) {
			return procs::pfnGlProgramUniformMatrix2dv(program, location, count, transpose, value);
		}
		void glProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble * value) {
			return procs::pfnGlProgramUniformMatrix3dv(program, location, count, transpose, value);
		}
		void glProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble * value) {
			return procs::pfnGlProgramUniformMatrix4dv(program, location, count, transpose, value);
		}
		void glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat * value) {
			return procs::pfnGlProgramUniformMatrix2x3fv(program, location, count, transpose, value);
		}
		void glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat * value) {
			return procs::pfnGlProgramUniformMatrix3x2fv(program, location, count, transpose, value);
		}
		void glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat * value) {
			return procs::pfnGlProgramUniformMatrix2x4fv(program, location, count, transpose, value);
		}
		void glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat * value) {
			return procs::pfnGlProgramUniformMatrix4x2fv(program, location, count, transpose, value);
		}
		void glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat * value) {
			return procs::pfnGlProgramUniformMatrix3x4fv(program, location, count, transpose, value);
		}
		void glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat * value) {
			return procs::pfnGlProgramUniformMatrix4x3fv(program, location, count, transpose, value);
		}
		void glProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble * value) {
			return procs::pfnGlProgramUniformMatrix2x3dv(program, location, count, transpose, value);
		}
		void glProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble * value) {
			return procs::pfnGlProgramUniformMatrix3x2dv(program, location, count, transpose, value);
		}
		void glProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble * value) {
			return procs::pfnGlProgramUniformMatrix2x4dv(program, location, count, transpose, value);
		}
		void glProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble * value) {
			return procs::pfnGlProgramUniformMatrix4x2dv(program, location, count, transpose, value);
		}
		void glProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble * value) {
			return procs::pfnGlProgramUniformMatrix3x4dv(program, location, count, transpose, value);
		}
		void glProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble * value) {
			return procs::pfnGlProgramUniformMatrix4x3dv(program, location, count, transpose, value);
		}
		void glValidateProgramPipeline(GLuint pipeline) {
			return procs::pfnGlValidateProgramPipeline(pipeline);
		}
		void glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei * length, GLchar * infoLog) {
			return procs::pfnGlGetProgramPipelineInfoLog(pipeline, bufSize, length, infoLog);
		}
		void glVertexAttribL1d(GLuint index, GLdouble x) {
			return procs::pfnGlVertexAttribL1d(index, x);
		}
		void glVertexAttribL2d(GLuint index, GLdouble x, GLdouble y) {
			return procs::pfnGlVertexAttribL2d(index, x, y);
		}
		void glVertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) {
			return procs::pfnGlVertexAttribL3d(index, x, y, z);
		}
		void glVertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
			return procs::pfnGlVertexAttribL4d(index, x, y, z, w);
		}
		void glVertexAttribL1dv(GLuint index, GLdouble * v) {
			return procs::pfnGlVertexAttribL1dv(index, v);
		}
		void glVertexAttribL2dv(GLuint index, GLdouble * v) {
			return procs::pfnGlVertexAttribL2dv(index, v);
		}
		void glVertexAttribL3dv(GLuint index, GLdouble * v) {
			return procs::pfnGlVertexAttribL3dv(index, v);
		}
		void glVertexAttribL4dv(GLuint index, GLdouble * v) {
			return procs::pfnGlVertexAttribL4dv(index, v);
		}
		void glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer) {
			return procs::pfnGlVertexAttribLPointer(index, size, type, stride, pointer);
		}
		void glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble * params) {
			return procs::pfnGlGetVertexAttribLdv(index, pname, params);
		}
		void glViewportArrayv(GLuint first, GLsizei count, GLfloat * v) {
			return procs::pfnGlViewportArrayv(first, count, v);
		}
		void glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h) {
			return procs::pfnGlViewportIndexedf(index, x, y, w, h);
		}
		void glViewportIndexedfv(GLuint index, GLfloat * v) {
			return procs::pfnGlViewportIndexedfv(index, v);
		}
		void glScissorArrayv(GLuint first, GLsizei count, GLint * v) {
			return procs::pfnGlScissorArrayv(first, count, v);
		}
		void glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height) {
			return procs::pfnGlScissorIndexed(index, left, bottom, width, height);
		}
		void glScissorIndexedv(GLuint index, GLint * v) {
			return procs::pfnGlScissorIndexedv(index, v);
		}
		void glDepthRangeArrayv(GLuint first, GLsizei count, GLdouble * v) {
			return procs::pfnGlDepthRangeArrayv(first, count, v);
		}
		void glDepthRangeIndexed(GLuint index, GLdouble n, GLdouble f) {
			return procs::pfnGlDepthRangeIndexed(index, n, f);
		}
		void glGetFloati_v(GLenum target, GLuint index, GLfloat * data) {
			return procs::pfnGlGetFloati_v(target, index, data);
		}
		void glGetDoublei_v(GLenum target, GLuint index, GLdouble * data) {
			return procs::pfnGlGetDoublei_v(target, index, data);
		}
		void glDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance) {
			return procs::pfnGlDrawArraysInstancedBaseInstance(mode, first, count, instancecount, baseinstance);
		}
		void glDrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLuint baseinstance) {
			return procs::pfnGlDrawElementsInstancedBaseInstance(mode, count, type, indices, instancecount, baseinstance);
		}
		void glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance) {
			return procs::pfnGlDrawElementsInstancedBaseVertexBaseInstance(mode, count, type, indices, instancecount, basevertex, baseinstance);
		}
		void glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint * params) {
			return procs::pfnGlGetInternalformativ(target, internalformat, pname, bufSize, params);
		}
		void glGetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint * params) {
			return procs::pfnGlGetActiveAtomicCounterBufferiv(program, bufferIndex, pname, params);
		}
		void glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format) {
			return procs::pfnGlBindImageTexture(unit, texture, level, layered, layer, access, format);
		}
		void glMemoryBarrier(GLbitfield barriers) {
			return procs::pfnGlMemoryBarrier(barriers);
		}
		void glTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) {
			return procs::pfnGlTexStorage1D(target, levels, internalformat, width);
		}
		void glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) {
			return procs::pfnGlTexStorage2D(target, levels, internalformat, width, height);
		}
		void glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) {
			return procs::pfnGlTexStorage3D(target, levels, internalformat, width, height, depth);
		}
		void glDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount) {
			return procs::pfnGlDrawTransformFeedbackInstanced(mode, id, instancecount);
		}
		void glDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount) {
			return procs::pfnGlDrawTransformFeedbackStreamInstanced(mode, id, stream, instancecount);
		}
		void glClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void * data) {
			return procs::pfnGlClearBufferData(target, internalformat, format, type, data);
		}
		void glClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data) {
			return procs::pfnGlClearBufferSubData(target, internalformat, offset, size, format, type, data);
		}
		void glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z) {
			return procs::pfnGlDispatchCompute(num_groups_x, num_groups_y, num_groups_z);
		}
		void glDispatchComputeIndirect(GLintptr indirect) {
			return procs::pfnGlDispatchComputeIndirect(indirect);
		}
		void glCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) {
			return procs::pfnGlCopyImageSubData(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
		}
		void glFramebufferParameteri(GLenum target, GLenum pname, GLint param) {
			return procs::pfnGlFramebufferParameteri(target, pname, param);
		}
		void glGetFramebufferParameteriv(GLenum target, GLenum pname, GLint * params) {
			return procs::pfnGlGetFramebufferParameteriv(target, pname, params);
		}
		void glGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 * params) {
			return procs::pfnGlGetInternalformati64v(target, internalformat, pname, bufSize, params);
		}
		void glInvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth) {
			return procs::pfnGlInvalidateTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth);
		}
		void glInvalidateTexImage(GLuint texture, GLint level) {
			return procs::pfnGlInvalidateTexImage(texture, level);
		}
		void glInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length) {
			return procs::pfnGlInvalidateBufferSubData(buffer, offset, length);
		}
		void glInvalidateBufferData(GLuint buffer) {
			return procs::pfnGlInvalidateBufferData(buffer);
		}
		void glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, GLenum * attachments) {
			return procs::pfnGlInvalidateFramebuffer(target, numAttachments, attachments);
		}
		void glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height) {
			return procs::pfnGlInvalidateSubFramebuffer(target, numAttachments, attachments, x, y, width, height);
		}
		void glMultiDrawArraysIndirect(GLenum mode, const void * indirect, GLsizei drawcount, GLsizei stride) {
			return procs::pfnGlMultiDrawArraysIndirect(mode, indirect, drawcount, stride);
		}
		void glMultiDrawElementsIndirect(GLenum mode, GLenum type, const void * indirect, GLsizei drawcount, GLsizei stride) {
			return procs::pfnGlMultiDrawElementsIndirect(mode, type, indirect, drawcount, stride);
		}
		void glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint * params) {
			return procs::pfnGlGetProgramInterfaceiv(program, programInterface, pname, params);
		}
		GLuint glGetProgramResourceIndex(GLuint program, GLenum programInterface, GLchar * name) {
			return procs::pfnGlGetProgramResourceIndex(program, programInterface, name);
		}
		void glGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name) {
			return procs::pfnGlGetProgramResourceName(program, programInterface, index, bufSize, length, name);
		}
		void glGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, GLenum * props, GLsizei bufSize, GLsizei * length, GLint * params) {
			return procs::pfnGlGetProgramResourceiv(program, programInterface, index, propCount, props, bufSize, length, params);
		}
		GLint glGetProgramResourceLocation(GLuint program, GLenum programInterface, GLchar * name) {
			return procs::pfnGlGetProgramResourceLocation(program, programInterface, name);
		}
		GLint glGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, GLchar * name) {
			return procs::pfnGlGetProgramResourceLocationIndex(program, programInterface, name);
		}
		void glShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding) {
			return procs::pfnGlShaderStorageBlockBinding(program, storageBlockIndex, storageBlockBinding);
		}
		void glTexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) {
			return procs::pfnGlTexBufferRange(target, internalformat, buffer, offset, size);
		}
		void glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) {
			return procs::pfnGlTexStorage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations);
		}
		void glTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {
			return procs::pfnGlTexStorage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations);
		}
		void glTextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers) {
			return procs::pfnGlTextureView(texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers);
		}
		void glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) {
			return procs::pfnGlBindVertexBuffer(bindingindex, buffer, offset, stride);
		}
		void glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) {
			return procs::pfnGlVertexAttribFormat(attribindex, size, type, normalized, relativeoffset);
		}
		void glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
			return procs::pfnGlVertexAttribIFormat(attribindex, size, type, relativeoffset);
		}
		void glVertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
			return procs::pfnGlVertexAttribLFormat(attribindex, size, type, relativeoffset);
		}
		void glVertexAttribBinding(GLuint attribindex, GLuint bindingindex) {
			return procs::pfnGlVertexAttribBinding(attribindex, bindingindex);
		}
		void glVertexBindingDivisor(GLuint bindingindex, GLuint divisor) {
			return procs::pfnGlVertexBindingDivisor(bindingindex, divisor);
		}
		void glDebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, GLuint * ids, GLboolean enabled) {
			return procs::pfnGlDebugMessageControl(source, type, severity, count, ids, enabled);
		}
		void glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, GLchar * buf) {
			return procs::pfnGlDebugMessageInsert(source, type, id, severity, length, buf);
		}
		void glDebugMessageCallback(GLDEBUGPROC callback, const void * userParam) {
			return procs::pfnGlDebugMessageCallback(callback, userParam);
		}
		GLuint glGetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog) {
			return procs::pfnGlGetDebugMessageLog(count, bufSize, sources, types, ids, severities, lengths, messageLog);
		}
		void glPushDebugGroup(GLenum source, GLuint id, GLsizei length, GLchar * message) {
			return procs::pfnGlPushDebugGroup(source, id, length, message);
		}
		void glPopDebugGroup() {
			return procs::pfnGlPopDebugGroup();
		}
		void glObjectLabel(GLenum identifier, GLuint name, GLsizei length, GLchar * label) {
			return procs::pfnGlObjectLabel(identifier, name, length, label);
		}
		void glGetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei * length, GLchar * label) {
			return procs::pfnGlGetObjectLabel(identifier, name, bufSize, length, label);
		}
		void glObjectPtrLabel(const void * ptr, GLsizei length, GLchar * label) {
			return procs::pfnGlObjectPtrLabel(ptr, length, label);
		}
		void glGetObjectPtrLabel(const void * ptr, GLsizei bufSize, GLsizei * length, GLchar * label) {
			return procs::pfnGlGetObjectPtrLabel(ptr, bufSize, length, label);
		}
		void glGetPointerv(GLenum pname, void ** params) {
			return procs::pfnGlGetPointerv(pname, params);
		}
		void glBufferStorage(GLenum target, GLsizeiptr size, const void * data, GLbitfield flags) {
			return procs::pfnGlBufferStorage(target, size, data, flags);
		}
		void glClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const void * data) {
			return procs::pfnGlClearTexImage(texture, level, format, type, data);
		}
		void glClearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * data) {
			return procs::pfnGlClearTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data);
		}
		void glBindBuffersBase(GLenum target, GLuint first, GLsizei count, GLuint * buffers) {
			return procs::pfnGlBindBuffersBase(target, first, count, buffers);
		}
		void glBindBuffersRange(GLenum target, GLuint first, GLsizei count, GLuint * buffers, GLintptr * offsets, GLsizeiptr * sizes) {
			return procs::pfnGlBindBuffersRange(target, first, count, buffers, offsets, sizes);
		}
		void glBindTextures(GLuint first, GLsizei count, GLuint * textures) {
			return procs::pfnGlBindTextures(first, count, textures);
		}
		void glBindSamplers(GLuint first, GLsizei count, GLuint * samplers) {
			return procs::pfnGlBindSamplers(first, count, samplers);
		}
		void glBindImageTextures(GLuint first, GLsizei count, GLuint * textures) {
			return procs::pfnGlBindImageTextures(first, count, textures);
		}
		void glBindVertexBuffers(GLuint first, GLsizei count, GLuint * buffers, GLintptr * offsets, GLsizei * strides) {
			return procs::pfnGlBindVertexBuffers(first, count, buffers, offsets, strides);
		}
		void glClipControl(GLenum origin, GLenum depth) {
			return procs::pfnGlClipControl(origin, depth);
		}
		void glCreateTransformFeedbacks(GLsizei n, GLuint * ids) {
			return procs::pfnGlCreateTransformFeedbacks(n, ids);
		}
		void glTransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer) {
			return procs::pfnGlTransformFeedbackBufferBase(xfb, index, buffer);
		}
		void glTransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) {
			return procs::pfnGlTransformFeedbackBufferRange(xfb, index, buffer, offset, size);
		}
		void glGetTransformFeedbackiv(GLuint xfb, GLenum pname, GLint * param) {
			return procs::pfnGlGetTransformFeedbackiv(xfb, pname, param);
		}
		void glGetTransformFeedbacki_v(GLuint xfb, GLenum pname, GLuint index, GLint * param) {
			return procs::pfnGlGetTransformFeedbacki_v(xfb, pname, index, param);
		}
		void glGetTransformFeedbacki64_v(GLuint xfb, GLenum pname, GLuint index, GLint64 * param) {
			return procs::pfnGlGetTransformFeedbacki64_v(xfb, pname, index, param);
		}
		void glCreateBuffers(GLsizei n, GLuint * buffers) {
			return procs::pfnGlCreateBuffers(n, buffers);
		}
		void glNamedBufferStorage(GLuint buffer, GLsizeiptr size, const void * data, GLbitfield flags) {
			return procs::pfnGlNamedBufferStorage(buffer, size, data, flags);
		}
		void glNamedBufferData(GLuint buffer, GLsizeiptr size, const void * data, GLenum usage) {
			return procs::pfnGlNamedBufferData(buffer, size, data, usage);
		}
		void glNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const void * data) {
			return procs::pfnGlNamedBufferSubData(buffer, offset, size, data);
		}
		void glCopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) {
			return procs::pfnGlCopyNamedBufferSubData(readBuffer, writeBuffer, readOffset, writeOffset, size);
		}
		void glClearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void * data) {
			return procs::pfnGlClearNamedBufferData(buffer, internalformat, format, type, data);
		}
		void glClearNamedBufferSubData(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void * data) {
			return procs::pfnGlClearNamedBufferSubData(buffer, internalformat, offset, size, format, type, data);
		}
		void * glMapNamedBuffer(GLuint buffer, GLenum access) {
			return procs::pfnGlMapNamedBuffer(buffer, access);
		}
		void * glMapNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access) {
			return procs::pfnGlMapNamedBufferRange(buffer, offset, length, access);
		}
		GLboolean glUnmapNamedBuffer(GLuint buffer) {
			return procs::pfnGlUnmapNamedBuffer(buffer);
		}
		void glFlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length) {
			return procs::pfnGlFlushMappedNamedBufferRange(buffer, offset, length);
		}
		void glGetNamedBufferParameteriv(GLuint buffer, GLenum pname, GLint * params) {
			return procs::pfnGlGetNamedBufferParameteriv(buffer, pname, params);
		}
		void glGetNamedBufferParameteri64v(GLuint buffer, GLenum pname, GLint64 * params) {
			return procs::pfnGlGetNamedBufferParameteri64v(buffer, pname, params);
		}
		void glGetNamedBufferPointerv(GLuint buffer, GLenum pname, void ** params) {
			return procs::pfnGlGetNamedBufferPointerv(buffer, pname, params);
		}
		void glGetNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, void * data) {
			return procs::pfnGlGetNamedBufferSubData(buffer, offset, size, data);
		}
		void glCreateFramebuffers(GLsizei n, GLuint * framebuffers) {
			return procs::pfnGlCreateFramebuffers(n, framebuffers);
		}
		void glNamedFramebufferRenderbuffer(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
			return procs::pfnGlNamedFramebufferRenderbuffer(framebuffer, attachment, renderbuffertarget, renderbuffer);
		}
		void glNamedFramebufferParameteri(GLuint framebuffer, GLenum pname, GLint param) {
			return procs::pfnGlNamedFramebufferParameteri(framebuffer, pname, param);
		}
		void glNamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level) {
			return procs::pfnGlNamedFramebufferTexture(framebuffer, attachment, texture, level);
		}
		void glNamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer) {
			return procs::pfnGlNamedFramebufferTextureLayer(framebuffer, attachment, texture, level, layer);
		}
		void glNamedFramebufferDrawBuffer(GLuint framebuffer, GLenum buf) {
			return procs::pfnGlNamedFramebufferDrawBuffer(framebuffer, buf);
		}
		void glNamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, GLenum * bufs) {
			return procs::pfnGlNamedFramebufferDrawBuffers(framebuffer, n, bufs);
		}
		void glNamedFramebufferReadBuffer(GLuint framebuffer, GLenum src) {
			return procs::pfnGlNamedFramebufferReadBuffer(framebuffer, src);
		}
		void glInvalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, GLenum * attachments) {
			return procs::pfnGlInvalidateNamedFramebufferData(framebuffer, numAttachments, attachments);
		}
		void glInvalidateNamedFramebufferSubData(GLuint framebuffer, GLsizei numAttachments, GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height) {
			return procs::pfnGlInvalidateNamedFramebufferSubData(framebuffer, numAttachments, attachments, x, y, width, height);
		}
		void glClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLint * value) {
			return procs::pfnGlClearNamedFramebufferiv(framebuffer, buffer, drawbuffer, value);
		}
		void glClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLuint * value) {
			return procs::pfnGlClearNamedFramebufferuiv(framebuffer, buffer, drawbuffer, value);
		}
		void glClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat * value) {
			return procs::pfnGlClearNamedFramebufferfv(framebuffer, buffer, drawbuffer, value);
		}
		void glClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) {
			return procs::pfnGlClearNamedFramebufferfi(framebuffer, buffer, drawbuffer, depth, stencil);
		}
		void glBlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {
			return procs::pfnGlBlitNamedFramebuffer(readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
		}
		GLenum glCheckNamedFramebufferStatus(GLuint framebuffer, GLenum target) {
			return procs::pfnGlCheckNamedFramebufferStatus(framebuffer, target);
		}
		void glGetNamedFramebufferParameteriv(GLuint framebuffer, GLenum pname, GLint * param) {
			return procs::pfnGlGetNamedFramebufferParameteriv(framebuffer, pname, param);
		}
		void glGetNamedFramebufferAttachmentParameteriv(GLuint framebuffer, GLenum attachment, GLenum pname, GLint * params) {
			return procs::pfnGlGetNamedFramebufferAttachmentParameteriv(framebuffer, attachment, pname, params);
		}
		void glCreateRenderbuffers(GLsizei n, GLuint * renderbuffers) {
			return procs::pfnGlCreateRenderbuffers(n, renderbuffers);
		}
		void glNamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height) {
			return procs::pfnGlNamedRenderbufferStorage(renderbuffer, internalformat, width, height);
		}
		void glNamedRenderbufferStorageMultisample(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {
			return procs::pfnGlNamedRenderbufferStorageMultisample(renderbuffer, samples, internalformat, width, height);
		}
		void glGetNamedRenderbufferParameteriv(GLuint renderbuffer, GLenum pname, GLint * params) {
			return procs::pfnGlGetNamedRenderbufferParameteriv(renderbuffer, pname, params);
		}
		void glCreateTextures(GLenum target, GLsizei n, GLuint * textures) {
			return procs::pfnGlCreateTextures(target, n, textures);
		}
		void glTextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer) {
			return procs::pfnGlTextureBuffer(texture, internalformat, buffer);
		}
		void glTextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) {
			return procs::pfnGlTextureBufferRange(texture, internalformat, buffer, offset, size);
		}
		void glTextureStorage1D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width) {
			return procs::pfnGlTextureStorage1D(texture, levels, internalformat, width);
		}
		void glTextureStorage2D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) {
			return procs::pfnGlTextureStorage2D(texture, levels, internalformat, width, height);
		}
		void glTextureStorage3D(GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) {
			return procs::pfnGlTextureStorage3D(texture, levels, internalformat, width, height, depth);
		}
		void glTextureStorage2DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) {
			return procs::pfnGlTextureStorage2DMultisample(texture, samples, internalformat, width, height, fixedsamplelocations);
		}
		void glTextureStorage3DMultisample(GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {
			return procs::pfnGlTextureStorage3DMultisample(texture, samples, internalformat, width, height, depth, fixedsamplelocations);
		}
		void glTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels) {
			return procs::pfnGlTextureSubImage1D(texture, level, xoffset, width, format, type, pixels);
		}
		void glTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels) {
			return procs::pfnGlTextureSubImage2D(texture, level, xoffset, yoffset, width, height, format, type, pixels);
		}
		void glTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels) {
			return procs::pfnGlTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
		}
		void glCompressedTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data) {
			return procs::pfnGlCompressedTextureSubImage1D(texture, level, xoffset, width, format, imageSize, data);
		}
		void glCompressedTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data) {
			return procs::pfnGlCompressedTextureSubImage2D(texture, level, xoffset, yoffset, width, height, format, imageSize, data);
		}
		void glCompressedTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data) {
			return procs::pfnGlCompressedTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
		}
		void glCopyTextureSubImage1D(GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
			return procs::pfnGlCopyTextureSubImage1D(texture, level, xoffset, x, y, width);
		}
		void glCopyTextureSubImage2D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
			return procs::pfnGlCopyTextureSubImage2D(texture, level, xoffset, yoffset, x, y, width, height);
		}
		void glCopyTextureSubImage3D(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
			return procs::pfnGlCopyTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, x, y, width, height);
		}
		void glTextureParameterf(GLuint texture, GLenum pname, GLfloat param) {
			return procs::pfnGlTextureParameterf(texture, pname, param);
		}
		void glTextureParameterfv(GLuint texture, GLenum pname, GLfloat * param) {
			return procs::pfnGlTextureParameterfv(texture, pname, param);
		}
		void glTextureParameteri(GLuint texture, GLenum pname, GLint param) {
			return procs::pfnGlTextureParameteri(texture, pname, param);
		}
		void glTextureParameterIiv(GLuint texture, GLenum pname, GLint * params) {
			return procs::pfnGlTextureParameterIiv(texture, pname, params);
		}
		void glTextureParameterIuiv(GLuint texture, GLenum pname, GLuint * params) {
			return procs::pfnGlTextureParameterIuiv(texture, pname, params);
		}
		void glTextureParameteriv(GLuint texture, GLenum pname, GLint * param) {
			return procs::pfnGlTextureParameteriv(texture, pname, param);
		}
		void glGenerateTextureMipmap(GLuint texture) {
			return procs::pfnGlGenerateTextureMipmap(texture);
		}
		void glBindTextureUnit(GLuint unit, GLuint texture) {
			return procs::pfnGlBindTextureUnit(unit, texture);
		}
		void glGetTextureImage(GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * pixels) {
			return procs::pfnGlGetTextureImage(texture, level, format, type, bufSize, pixels);
		}
		void glGetCompressedTextureImage(GLuint texture, GLint level, GLsizei bufSize, void * pixels) {
			return procs::pfnGlGetCompressedTextureImage(texture, level, bufSize, pixels);
		}
		void glGetTextureLevelParameterfv(GLuint texture, GLint level, GLenum pname, GLfloat * params) {
			return procs::pfnGlGetTextureLevelParameterfv(texture, level, pname, params);
		}
		void glGetTextureLevelParameteriv(GLuint texture, GLint level, GLenum pname, GLint * params) {
			return procs::pfnGlGetTextureLevelParameteriv(texture, level, pname, params);
		}
		void glGetTextureParameterfv(GLuint texture, GLenum pname, GLfloat * params) {
			return procs::pfnGlGetTextureParameterfv(texture, pname, params);
		}
		void glGetTextureParameterIiv(GLuint texture, GLenum pname, GLint * params) {
			return procs::pfnGlGetTextureParameterIiv(texture, pname, params);
		}
		void glGetTextureParameterIuiv(GLuint texture, GLenum pname, GLuint * params) {
			return procs::pfnGlGetTextureParameterIuiv(texture, pname, params);
		}
		void glGetTextureParameteriv(GLuint texture, GLenum pname, GLint * params) {
			return procs::pfnGlGetTextureParameteriv(texture, pname, params);
		}
		void glCreateVertexArrays(GLsizei n, GLuint * arrays) {
			return procs::pfnGlCreateVertexArrays(n, arrays);
		}
		void glDisableVertexArrayAttrib(GLuint vaobj, GLuint index) {
			return procs::pfnGlDisableVertexArrayAttrib(vaobj, index);
		}
		void glEnableVertexArrayAttrib(GLuint vaobj, GLuint index) {
			return procs::pfnGlEnableVertexArrayAttrib(vaobj, index);
		}
		void glVertexArrayElementBuffer(GLuint vaobj, GLuint buffer) {
			return procs::pfnGlVertexArrayElementBuffer(vaobj, buffer);
		}
		void glVertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) {
			return procs::pfnGlVertexArrayVertexBuffer(vaobj, bindingindex, buffer, offset, stride);
		}
		void glVertexArrayVertexBuffers(GLuint vaobj, GLuint first, GLsizei count, GLuint * buffers, GLintptr * offsets, GLsizei * strides) {
			return procs::pfnGlVertexArrayVertexBuffers(vaobj, first, count, buffers, offsets, strides);
		}
		void glVertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex) {
			return procs::pfnGlVertexArrayAttribBinding(vaobj, attribindex, bindingindex);
		}
		void glVertexArrayAttribFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) {
			return procs::pfnGlVertexArrayAttribFormat(vaobj, attribindex, size, type, normalized, relativeoffset);
		}
		void glVertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
			return procs::pfnGlVertexArrayAttribIFormat(vaobj, attribindex, size, type, relativeoffset);
		}
		void glVertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
			return procs::pfnGlVertexArrayAttribLFormat(vaobj, attribindex, size, type, relativeoffset);
		}
		void glVertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor) {
			return procs::pfnGlVertexArrayBindingDivisor(vaobj, bindingindex, divisor);
		}
		void glGetVertexArrayiv(GLuint vaobj, GLenum pname, GLint * param) {
			return procs::pfnGlGetVertexArrayiv(vaobj, pname, param);
		}
		void glGetVertexArrayIndexediv(GLuint vaobj, GLuint index, GLenum pname, GLint * param) {
			return procs::pfnGlGetVertexArrayIndexediv(vaobj, index, pname, param);
		}
		void glGetVertexArrayIndexed64iv(GLuint vaobj, GLuint index, GLenum pname, GLint64 * param) {
			return procs::pfnGlGetVertexArrayIndexed64iv(vaobj, index, pname, param);
		}
		void glCreateSamplers(GLsizei n, GLuint * samplers) {
			return procs::pfnGlCreateSamplers(n, samplers);
		}
		void glCreateProgramPipelines(GLsizei n, GLuint * pipelines) {
			return procs::pfnGlCreateProgramPipelines(n, pipelines);
		}
		void glCreateQueries(GLenum target, GLsizei n, GLuint * ids) {
			return procs::pfnGlCreateQueries(target, n, ids);
		}
		void glGetQueryBufferObjecti64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) {
			return procs::pfnGlGetQueryBufferObjecti64v(id, buffer, pname, offset);
		}
		void glGetQueryBufferObjectiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) {
			return procs::pfnGlGetQueryBufferObjectiv(id, buffer, pname, offset);
		}
		void glGetQueryBufferObjectui64v(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) {
			return procs::pfnGlGetQueryBufferObjectui64v(id, buffer, pname, offset);
		}
		void glGetQueryBufferObjectuiv(GLuint id, GLuint buffer, GLenum pname, GLintptr offset) {
			return procs::pfnGlGetQueryBufferObjectuiv(id, buffer, pname, offset);
		}
		void glMemoryBarrierByRegion(GLbitfield barriers) {
			return procs::pfnGlMemoryBarrierByRegion(barriers);
		}
		void glGetTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void * pixels) {
			return procs::pfnGlGetTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, bufSize, pixels);
		}
		void glGetCompressedTextureSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void * pixels) {
			return procs::pfnGlGetCompressedTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels);
		}
		GLenum glGetGraphicsResetStatus() {
			return procs::pfnGlGetGraphicsResetStatus();
		}
		void glGetnCompressedTexImage(GLenum target, GLint lod, GLsizei bufSize, void * pixels) {
			return procs::pfnGlGetnCompressedTexImage(target, lod, bufSize, pixels);
		}
		void glGetnTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void * pixels) {
			return procs::pfnGlGetnTexImage(target, level, format, type, bufSize, pixels);
		}
		void glGetnUniformdv(GLuint program, GLint location, GLsizei bufSize, GLdouble * params) {
			return procs::pfnGlGetnUniformdv(program, location, bufSize, params);
		}
		void glGetnUniformfv(GLuint program, GLint location, GLsizei bufSize, GLfloat * params) {
			return procs::pfnGlGetnUniformfv(program, location, bufSize, params);
		}
		void glGetnUniformiv(GLuint program, GLint location, GLsizei bufSize, GLint * params) {
			return procs::pfnGlGetnUniformiv(program, location, bufSize, params);
		}
		void glGetnUniformuiv(GLuint program, GLint location, GLsizei bufSize, GLuint * params) {
			return procs::pfnGlGetnUniformuiv(program, location, bufSize, params);
		}
		void glReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void * data) {
			return procs::pfnGlReadnPixels(x, y, width, height, format, type, bufSize, data);
		}
		void glGetnMapdv(GLenum target, GLenum query, GLsizei bufSize, GLdouble * v) {
			return procs::pfnGlGetnMapdv(target, query, bufSize, v);
		}
		void glGetnMapfv(GLenum target, GLenum query, GLsizei bufSize, GLfloat * v) {
			return procs::pfnGlGetnMapfv(target, query, bufSize, v);
		}
		void glGetnMapiv(GLenum target, GLenum query, GLsizei bufSize, GLint * v) {
			return procs::pfnGlGetnMapiv(target, query, bufSize, v);
		}
		void glGetnPixelMapfv(GLenum map, GLsizei bufSize, GLfloat * values) {
			return procs::pfnGlGetnPixelMapfv(map, bufSize, values);
		}
		void glGetnPixelMapuiv(GLenum map, GLsizei bufSize, GLuint * values) {
			return procs::pfnGlGetnPixelMapuiv(map, bufSize, values);
		}
		void glGetnPixelMapusv(GLenum map, GLsizei bufSize, GLushort * values) {
			return procs::pfnGlGetnPixelMapusv(map, bufSize, values);
		}
		void glGetnPolygonStipple(GLsizei bufSize, GLubyte * pattern) {
			return procs::pfnGlGetnPolygonStipple(bufSize, pattern);
		}
		void glGetnColorTable(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void * table) {
			return procs::pfnGlGetnColorTable(target, format, type, bufSize, table);
		}
		void glGetnConvolutionFilter(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void * image) {
			return procs::pfnGlGetnConvolutionFilter(target, format, type, bufSize, image);
		}
		void glGetnSeparableFilter(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void * row, GLsizei columnBufSize, void * column, void * span) {
			return procs::pfnGlGetnSeparableFilter(target, format, type, rowBufSize, row, columnBufSize, column, span);
		}
		void glGetnHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void * values) {
			return procs::pfnGlGetnHistogram(target, reset, format, type, bufSize, values);
		}
		void glGetnMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void * values) {
			return procs::pfnGlGetnMinmax(target, reset, format, type, bufSize, values);
		}
		void glTextureBarrier() {
			return procs::pfnGlTextureBarrier();
		}
		void glSpecializeShader(GLuint shader, GLchar * pEntryPoint, GLuint numSpecializationConstants, GLuint * pConstantIndex, GLuint * pConstantValue) {
			return procs::pfnGlSpecializeShader(shader, pEntryPoint, numSpecializationConstants, pConstantIndex, pConstantValue);
		}
		void glMultiDrawArraysIndirectCount(GLenum mode, const void * indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) {
			return procs::pfnGlMultiDrawArraysIndirectCount(mode, indirect, drawcount, maxdrawcount, stride);
		}
		void glMultiDrawElementsIndirectCount(GLenum mode, GLenum type, const void * indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) {
			return procs::pfnGlMultiDrawElementsIndirectCount(mode, type, indirect, drawcount, maxdrawcount, stride);
		}
		void glPolygonOffsetClamp(GLfloat factor, GLfloat units, GLfloat clamp) {
			return procs::pfnGlPolygonOffsetClamp(factor, units, clamp);
		}
	}
