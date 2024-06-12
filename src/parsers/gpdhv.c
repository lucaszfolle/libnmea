#include "../nmea/parser_types.h"
#include "gpdhv.h"
#include "parse.h"

int init(nmea_parser_s *parser)
{
	/* Declare what sentence type to parse */
	NMEA_PARSER_TYPE(parser, NMEA_GPDHV);
	NMEA_PARSER_PREFIX(parser, "GPDHV");
	return 0;
}

int allocate_data(nmea_parser_s *parser)
{
	parser->data = malloc(sizeof(nmea_gpdhv_s));
	if (NULL == parser->data)
	{
		return -1;
	}

	return 0;
}

int set_default(nmea_parser_s *parser)
{
	memset(parser->data, 0, sizeof(nmea_gpdhv_s));
	return 0;
}

int free_data(nmea_s *data)
{
	free(data);
	return 0;
}

int parse(nmea_parser_s *parser, char *value, int val_index)
{
	nmea_gpdhv_s *data = (nmea_gpdhv_s *)parser->data;

	switch (val_index)
	{
	case NMEA_GPDHV_TIME:
		/* Parse time */
		if (-1 == nmea_time_parse(value, &data->time))
		{
			return -1;
		}
		break;

	case NMEA_GPDHV_3D_SPEED_MPS:
		data->speed_3d_mps = atof(value);
		break;

	case NMEA_GPDHV_X_SPEED_MPS:
		data->speed_x_mps = atof(value);
		break;

	case NMEA_GPDHV_Y_SPEED_MPS:
		data->speed_y_mps = atof(value);
		break;

	case NMEA_GPDHV_Z_SPEED_MPS:
		data->speed_z_mps = atof(value);
		break;

	case NMEA_GPDHV_GROUND_SPEED_KMPH:
		data->gndspd_kmph = atof(value);
		break;

	default:
		break;
	}

	return 0;
}
