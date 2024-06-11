#include "../nmea/parser_types.h"
#include "gpzda.h"
#include "parse.h"

int init(nmea_parser_s *parser)
{
	/* Declare what sentence type to parse */
	NMEA_PARSER_TYPE(parser, NMEA_GPZDA);
	NMEA_PARSER_PREFIX(parser, "GPZDA");
	return 0;
}

int allocate_data(nmea_parser_s *parser)
{
	parser->data = malloc(sizeof(nmea_gpzda_s));
	if (NULL == parser->data)
	{
		return -1;
	}

	return 0;
}

int set_default(nmea_parser_s *parser)
{
	memset(parser->data, 0, sizeof(nmea_gpzda_s));
	return 0;
}

int free_data(nmea_s *data)
{
	free(data);
	return 0;
}

int parse(nmea_parser_s *parser, char *value, int val_index)
{
	nmea_gpzda_s *data = (nmea_gpzda_s *)parser->data;

	int tmp;
	switch (val_index)
	{
	case NMEA_GPZDA_TIME:
		/* Parse time */
		if (-1 == nmea_time_parse(value, &data->date_time))
		{
			return -1;
		}
		break;

	case NMEA_GPZDA_DAY:
		data->date_time->day = atoi(value);
		break;

	case NMEA_GPZDA_MONTH:
		data->date_time->month = atoi(value);
		break;

	case NMEA_GPZDA_YEAR:
		tmp = atoi(value);
		if (tmp < 2000)
			return -1;
		data->date_time->year = tmp - 2000;
		break;

	default:
		break;
	}

	return 0;
}
