#include "../nmea/parser_types.h"
#include "gpgst.h"
#include "parse.h"

int init(nmea_parser_s *parser)
{
	/* Declare what sentence type to parse */
	NMEA_PARSER_TYPE(parser, NMEA_GPGST);
	NMEA_PARSER_PREFIX(parser, "GPGST");
	return 0;
}

int allocate_data(nmea_parser_s *parser)
{
	parser->data = malloc(sizeof(nmea_gpgst_s));
	if (NULL == parser->data)
	{
		return -1;
	}

	return 0;
}

int set_default(nmea_parser_s *parser)
{
	memset(parser->data, 0, sizeof(nmea_gpgst_s));
	return 0;
}

int free_data(nmea_s *data)
{
	free(data);
	return 0;
}

int parse(nmea_parser_s *parser, char *value, int val_index)
{
	nmea_gpgst_s *data = (nmea_gpgst_s *)parser->data;

	switch (val_index)
	{

	case NMEA_GPGST_TIME:
		/* Parse time */
		if (-1 == nmea_time_parse(value, &data->time))
		{
			return -1;
		}
		break;

	case NMEA_GPGST_STDDEV_RMS_M:
		data->stddev_rms_m = atof(value);
		break;

	case NMEA_GPGST_STDDEV_LAT_M:
		data->stddev_lat_m = atof(value);

		break;

	case NMEA_GPGST_STDDEV_LON_M:
		data->stddev_lon_m = atof(value);
		break;

	case NMEA_GPGST_STDDEV_ALT_M:
		data->stddev_alt_m = atof(value);
		break;

	default:
		break;
	}

	return 0;
}
