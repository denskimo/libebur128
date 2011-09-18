#ifndef SCANNER_COMMON_H
#define SCANNER_COMMON_H

#include "ebur128.h"
#include "input.h"
#include "filetree.h"

#include <glib.h>

struct file_data
{
    ebur128_state *st;
    size_t number_of_frames;
    size_t number_of_elapsed_frames;
    GMutex *mutex;
    double loudness;
    double lra;
    double peak;
    double true_peak;
    gboolean scanned;
};

struct scan_opts
{
    gboolean lra;
    gchar *peak;
};

int open_plugin(const char *raw, const char *display,
                struct input_ops **ops,
                struct input_handle **ih,
                FILE **file);
void init_and_get_number_of_frames(gpointer user, gpointer user_data);
void sum_frames(gpointer user, gpointer user_data);
void init_state_and_scan_work_item(gpointer user, gpointer user_data);
void init_state_and_scan(gpointer user, gpointer user_data);
void destroy_state(gpointer user, gpointer user_data);
void get_state(gpointer user, gpointer user_data);
void get_max_peaks(gpointer user, gpointer user_data);
gpointer print_progress_bar(gpointer data);

#endif /* end of include guard: SCANNER_COMMON_H */