#include <ctype.h>

#include "../nmea/parser_types.h"
#include "gpgsa.h"
#include "parse.h"

int init(nmea_parser_s *parser)
{
	/* Declare what sentence type to parse */
	NMEA_PARSER_TYPE(parser, NMEA_GPGSA);
	NMEA_PARSER_PREFIX(parser, "GPGSA");
	return 0;
}

int allocate_data(nmea_parser_s *parser)
{
	parser->data = malloc(sizeof(nmea_gpgsa_s));
	if (NULL == parser->data)
	{
		return -1;
	}

	return 0;
}

int set_default(nmea_parser_s *parser)
{
	memset(parser->data, 0, sizeof(nmea_gpgsa_s));
	return 0;
}

int free_data(nmea_s *data)
{
	free(data);
	return 0;
}

int parse(nmea_parser_s *parser, char *value, int val_index)
{
	nmea_gpgsa_s *data = (nmea_gpgsa_s *)parser->data;

	switch (val_index)
	{
	case NMEA_GPGSA_MODE:
		data->mode = *value;
		if (('M' != toupper(data->mode)) && ('A' != toupper(data->mode)))
		{
			return -1;
		}
		break;
	case NMEA_GPGSA_FIXTYPE:
		data->fixtype = strtol(value, NULL, 10);
		if ((data->fixtype < 1) || (data->fixtype > 3))
		{
			return -1;
		}
		break;
	case NMEA_GPGSA_PDOP:
		data->pdop = atof(value);
		break;
	case NMEA_GPGSA_HDOP:
		data->hdop = atof(value);
		break;
	case NMEA_GPGSA_VDOP:
		data->vdop = atof(value);
		break;
	default:
		break;
	}

	/* Treats the satellites IDs */
	if ((val_index >= NMEA_GPGSA_SATID_00) && (val_index <= NMEA_GPGSA_SATID_11))
	{
		data->satID[val_index - NMEA_GPGSA_SATID_00] = strtol(value, NULL, 10);
	}

	return 0;
}
