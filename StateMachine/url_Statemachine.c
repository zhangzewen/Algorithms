#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct http_parse_st{
	char *method_start;
	char *method_end;
	char *path_start;
	char *path_end;
	char *version_start;
	char *version_end;
	char *key_start;
	char *key_end;
	char *value_start;
	char *value_end;
};


void do_method(const char *start, const char *end)
{
	char buff[BUFSIZ] = {0};
	strncpy(buff, start, end - start);

	printf("method = %s\n", buff);
}

void do_path(const char *start, const char *end)
{
	char buff[BUFSIZ] = {0};
	strncpy(buff, start, end - start);

	printf("path = %s\n", buff);
}

void do_version(const char *start, const char *end)
{
	char buff[BUFSIZ] = {0};
	strncpy(buff, start, end - start);

	printf("version = %s\n", buff);
}

void do_kv(const char *key_start, const char *key_end, const char *value_start, const char *value_end)
{
	char buff[BUFSIZ] = {0};
	strncpy(buff, key_start, key_end - key_start);
	strncat(buff, ": ", strlen(": "));

	strncat(buff, value_start, value_end - value_start);
	
	printf("K/V -- >%s\n", buff);
}


typedef struct http_parse_st http_parse_t;
int parse_http_request_header(http_parse_t *r, char *buff)
{
	char *p = NULL;
	char ch = '\0';
	char c = '\0';
	enum {
		sw_start = 0,
		sw_key,
		sw_key_end,
		sw_separator,
		sw_value,
		sw_kv_almost_done,
		sw_kv_done,
		sw_request_header_almost_done,
		sw_request_header_done
	}state;

	state = sw_start;
  for (p = buff; ; p++) {
		ch = *p;
		if (ch == '\0' || ch == '0') {
			break;
		}
	
		switch (state) {
			case sw_start:
				if (ch == '\r' || ch == '\n') {
					state = sw_kv_done;
				}
				
				c = ch | 0x20;
	
				if (c >= 'a' && c <= 'z') {
					state = sw_key;
					r->key_start = p;	
				}
			
				break;

			case sw_key:
				if (ch == ':') {
					state = sw_separator;
					r->key_end = p;
					break;
				}
				c = ch | 0x20;
	
				if (c >= 'a' && c <= 'z') {
					state = sw_key;
				}

				break;
			case sw_separator:
				if (ch == ' ' || ch == '\t') {
					state = sw_separator;
					break;
				}
				state = sw_value;
				r->value_start = p;
				break;
			case sw_value:
				if (ch == '\r') {
					r->value_end = p;
					state = sw_kv_almost_done;
					break;
				}
				state = sw_value;
				break;

			case sw_kv_almost_done:
				if (ch == '\n') {
					state == sw_kv_almost_done;
					do_kv(r->key_start, r->key_end, r->value_start, r->value_end);
				}
				state = sw_kv_done;
				break;
			case sw_kv_done:
				if (ch != '\r' && ch != '\n') {
					state = sw_start;
					p--;
					break;
				} else {
					return 0;
				}
				break;
		}	
	}
}

int parse_http_request_line(http_parse_t *r, char *buff)
{
	char  ch;
	char  *p;
	char  *tmp;
	int count = 0;
	enum {
		sw_start = 0,
		sw_method,
		sw_spaces_before_uri,
		sw_uri,
		sw_spaces_after_uri,
		sw_spaces_before_version,
		sw_version,
		sw_request_line_parse_almost_done,
		sw_request_line_parse_done,
		sw_almost_done,
		sw_done

	} state;

	state = sw_start;

	for (p = buff; ; p++) {
		ch = *p;

		if (ch == '\0' || ch == '0') {
			break;
		}

		switch (state) {

			case sw_start:
				r->method_start = p;

				if (ch == '\r' || ch == '\n') {
					break;
				}

				if (ch < 'A' || ch > 'Z') {
					return -1;
				}

				state = sw_method;
				break;

			case sw_method:
				if (ch == ' ') {
					r->method_end = p;

					do_method(r->method_start, r->method_end);

					state = sw_spaces_before_uri;
					break;
				}

				if (ch < 'A' || ch > 'Z') {
					return -1;
				}

				break;

			case sw_spaces_before_uri:

				if (ch == '/') {
					r->path_start = p;
					state = sw_uri;
					break;
				}

			case sw_uri:
				if (ch == ' ') {
					state = sw_spaces_before_version;
					r->path_end = p;
					do_path(r->path_start, r->path_end);
				} 
				if (count > 1024) {
					printf("url to large!\n");
					return -1;
				}
				count++;

				break;
			case sw_spaces_before_version:
				if (ch == 'H') {
					state = sw_version;
					r->version_start = p;
					break;
				}

			case sw_version:
				if (ch == '\r') {
					state = sw_request_line_parse_almost_done;
					r->version_end = p;
					do_version(r->version_start, r->version_end);
				}	

				break;
			case sw_request_line_parse_almost_done:
				if (ch == '\n') {
					state = sw_request_line_parse_done;
				}
				break;
			case sw_request_line_parse_done:
				if (ch == '\r') {
					tmp = p;
					state = sw_almost_done;
				} else {
					return -1;

				}
				break;
			case sw_almost_done:
				if (ch == '\n' && *tmp == '\r') {
					state = sw_done;
				}else {
					return -1;
				}
				break;

			default:
				break;

		}
	}
	return 0;
}


int main(int args, char *argv[])
{
	char url_1[] = "GET / HTTP/1.1\r\n\r\n";
	char url_2[] = "GET /html/index.php HTTP/1.1\r\n\r\n";
//	char url_2[] = "GET / HTTP/1.1\r\nHost: www.baidu.com\r\n\r\n";
//	char url_3[] = "GET /html/index.php HTTP/1.1\r\nHoset: www.baidu.com\r\n\r\n";

	char header_1[] = "Host: www.baidu.com\r\n";
	char header_2[] = "Host: www.baidu.com\r\nConnection: Keep-alive\r\n";
	char header_3[] = "Host: www.baidu.com\r\nConnection: Keep-alive\r\n\r\n";
	int ret = 0;
	
	http_parse_t r;
	
	ret = parse_http_request_line(&r, url_2);
	if (ret == -1) {
		puts("error!");
	}

	if (ret == 0) {
		puts("ok,done");
	}
	ret = parse_http_request_header(&r, header_3);
	return 0;
	
}

