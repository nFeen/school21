#include "../s21_string.h"
#include "test_runner.h"

START_TEST(sprintf_test_c1) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "%cirst", 'F');
  int cnt2 = s21_sprintf(buf2, "%cirst", 'F');
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_c2) {
  char buf1[100] = "this is string";
  char buf2[100] = "this is string";
  int cnt1 = sprintf(buf1, "%cirst", 'F');
  int cnt2 = s21_sprintf(buf2, "%cirst", 'F');
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_c3) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "First%2cecond", 's');
  int cnt2 = s21_sprintf(buf2, "First%2cecond", 's');
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_c4) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "First%-2cecond", 's');
  int cnt2 = s21_sprintf(buf2, "First%-2cecond", 's');
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_c5) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "First%cecond", 's');
  int cnt2 = s21_sprintf(buf2, "First%cecond", 's');
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_c6) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "%c%c%c%c", 't', 'e', 's', 't');
  int cnt2 = s21_sprintf(buf2, "%c%c%c%c", 't', 'e', 's', 't');
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_c7) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "%c%c", '2', '1');
  int cnt2 = s21_sprintf(buf2, "%c%c", '2', '1');
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_lc1) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "%lcirst", 'F');
  int cnt2 = s21_sprintf(buf2, "%lcirst", 'F');
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_lc2) {
  char buf1[100] = "this is string";
  char buf2[100] = "this is string";
  int cnt1 = sprintf(buf1, "%cirst", 'F');
  int cnt2 = s21_sprintf(buf2, "%cirst", 'F');
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_lc3) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "First%2lcecond", 's');
  int cnt2 = s21_sprintf(buf2, "First%2lcecond", 's');
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_lc4) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "First%-2lcecond", 's');
  int cnt2 = s21_sprintf(buf2, "First%-2lcecond", 's');
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_lc5) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "First%lcecond", 's');
  int cnt2 = s21_sprintf(buf2, "First%lcecond", 's');
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_lc6) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "%lc%lc%lc%lc", 't', 'e', 's', 't');
  int cnt2 = s21_sprintf(buf2, "%lc%lc%lc%lc", 't', 'e', 's', 't');
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_lc7) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "%lc%lc", '2', '1');
  int cnt2 = s21_sprintf(buf2, "%lc%lc", '2', '1');
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_d1) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "test %d%d%d", 1, 2, 3);
  int cnt2 = s21_sprintf(buf2, "test %d%d%d", 1, 2, 3);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_d2) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "test %+3d% 3d%+3d", 10, 20, -30);
  int cnt2 = s21_sprintf(buf2, "test %+3d% 3d%+3d", 10, 20, -30);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_d3) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "test %+5.2d% 5.3d%+5.4d", 100, 200, -300);
  int cnt2 = s21_sprintf(buf2, "test %+5.2d% 5.3d%+5.4d", 100, 200, -300);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_d4) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "test %-+5.2d% 5.3d%+5.4d", 100, 200, -300);
  int cnt2 = s21_sprintf(buf2, "test %-+5.2d% 5.3d%+5.4d", 100, 200, -300);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_d6) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "%10d", 2147483647);
  int cnt2 = s21_sprintf(buf2, "%10d", 2147483647);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_d7) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "%10d", -2147483647);
  int cnt2 = s21_sprintf(buf2, "%10d", -2147483647);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_d8) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "%10ld", 21474836488);
  int cnt2 = s21_sprintf(buf2, "%10ld", 21474836488);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_d9) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "%10ld", -21474836488);
  int cnt2 = s21_sprintf(buf2, "%10ld", -21474836488);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_d10) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "%10d", 55643);
  int cnt2 = s21_sprintf(buf2, "%10d", 55643);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_d11) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "%.0d", 0);
  int cnt2 = s21_sprintf(buf2, "%.0d", 0);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_d12) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "%d", 0);
  int cnt2 = s21_sprintf(buf2, "%d", 0);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_d13) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "%.1d", 0);
  int cnt2 = s21_sprintf(buf2, "%.1d", 0);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_f2) {
  char buf1[200];
  char buf2[200];
  int cnt1 = sprintf(buf1, "%.0f", (float)0);
  int cnt2 = s21_sprintf(buf2, "%.0f", (float)0);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_f21) {
  char buf1[200];
  char buf2[200];
  int cnt1 = sprintf(buf1, "%-.7f%.7f%-.7f", (float)5678.565656,
                     (float)678321.243242, (float)3456789123.43245);
  int cnt2 = s21_sprintf(buf2, "%-.7f%.7f%-.7f", (float)5678.565656,
                         (float)678321.243242, (float)3456789123.43245);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}
START_TEST(sprintf_test_f22) {
  char buf1[200];
  char buf2[200];
  int cnt1 =
      sprintf(buf1, "%-f%+f%+-f%-+f", (float)-5678, (float)+678321.243242,
              (float)3456789123.43245, (float)-4325678.43242);
  int cnt2 =
      s21_sprintf(buf2, "%-f%+f%+-f%-+f", (float)-5678, (float)+678321.243242,
                  (float)3456789123.43245, (float)-4325678.43242);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}
START_TEST(sprintf_test_f23) {
  char buf1[200];
  char buf2[200];
  int cnt1 = sprintf(buf1, "%-15f%+20f%+35.5f%-40.7f", (float)-5678,
                     (float)+678321.2432, (float)3456789123.43245,
                     (float)-4325678.43242);
  int cnt2 = s21_sprintf(buf2, "%-15f%+20f%+35.5f%-40.7f", (float)-5678,
                         (float)+678321.2432, (float)3456789123.43245,
                         (float)-4325678.43242);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_f3) {
  char buf1[200];
  char buf2[200];
  int cnt1 = sprintf(buf1, "%f", (float)512);
  int cnt2 = s21_sprintf(buf2, "%f", (float)512);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_s1) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "name: %s", "Sasha");
  int cnt2 = s21_sprintf(buf2, "name: %s", "Sasha");
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_s2) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "name: %6s", "Sasha");
  int cnt2 = s21_sprintf(buf2, "name: %6s", "Sasha");
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_s3) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "name: %s", "Sasha");
  int cnt2 = s21_sprintf(buf2, "name: %s", "Sasha");
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_s4) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "name: %-6send", "Sasha");
  int cnt2 = s21_sprintf(buf2, "name: %-6send", "Sasha");
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_s5) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "name: <%6s>", "");
  int cnt2 = s21_sprintf(buf2, "name: <%6s>", "");
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_s6) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "%s: %-6s", "name", "Sasha");
  int cnt2 = s21_sprintf(buf2, "%s: %-6s", "name", "Sasha");
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_s7) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "%.3s: %s", "name", "Sasha");
  int cnt2 = s21_sprintf(buf2, "%.3s: %s", "name", "Sasha");
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_s8) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "%6.3s: %5.3s", "name", "Sasha");
  int cnt2 = s21_sprintf(buf2, "%6.3s: %5.3s", "name", "Sasha");
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_ls1) {
  char buf1[100];
  char buf2[100];
  wchar_t str[] = L"Sasha";
  int cnt1 = sprintf(buf1, "name: %ls", str);
  int cnt2 = s21_sprintf(buf2, "name: %ls", str);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_ls2) {
  char buf1[100];
  char buf2[100];
  wchar_t str[] = L"Sasha";
  int cnt1 = sprintf(buf1, "name: %6ls", str);
  int cnt2 = s21_sprintf(buf2, "name: %6ls", str);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_ls4) {
  char buf1[100];
  char buf2[100];
  wchar_t str[] = L"Sasha";
  int cnt1 = sprintf(buf1, "name: %-6lsend", str);
  int cnt2 = s21_sprintf(buf2, "name: %-6lsend", str);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_ls5) {
  char buf1[100];
  char buf2[100];
  wchar_t str[] = L"";
  int cnt1 = sprintf(buf1, "name: <%6ls>", str);
  int cnt2 = s21_sprintf(buf2, "name: <%6ls>", str);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_ls6) {
  char buf1[100];
  char buf2[100];
  wchar_t str1[] = L"name";
  wchar_t str2[] = L"Sasha";
  int cnt1 = sprintf(buf1, "%ls: %-6ls", str1, str2);
  int cnt2 = s21_sprintf(buf2, "%ls: %-6ls", str1, str2);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_ls7) {
  char buf1[100];
  char buf2[100];
  wchar_t str1[] = L"name";
  wchar_t str2[] = L"Sasha";
  int cnt1 = sprintf(buf1, "%.3ls: %.3ls", str1, str2);
  int cnt2 = s21_sprintf(buf2, "%.3ls: %.3ls", str1, str2);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_ls8) {
  char buf1[100];
  char buf2[100];
  wchar_t str1[] = L"name";
  wchar_t str2[] = L"Sasha";
  int cnt1 = sprintf(buf1, "%6.3ls: %5.3ls", str1, str2);
  int cnt2 = s21_sprintf(buf2, "%6.3ls: %5.3ls", str1, str2);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_u1) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "%u%3u%.3u%5.6u%u", 123u, 20u, 345u, 799u, 0u);
  int cnt2 = s21_sprintf(buf2, "%u%3u%.3u%5.6u%u", 123u, 20u, 345u, 799u, 0u);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

START_TEST(sprintf_test_u2) {
  char buf1[100];
  char buf2[100];
  int cnt1 = sprintf(buf1, "%u%-3u%.3u%-5.6u%-u", 123u, 20u, 345u, 799u, 0u);
  int cnt2 =
      s21_sprintf(buf2, "%u%-3u%.3u%-5.6u%-u", 123u, 20u, 345u, 799u, 0u);
  ck_assert_str_eq(buf1, buf2);
  ck_assert_int_eq(cnt1, cnt2);
}

Suite *s21_sprintf_cases() {
  Suite *s = suite_create("suite_sprintf");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_test_c1);
  tcase_add_test(tc, sprintf_test_c2);
  tcase_add_test(tc, sprintf_test_c3);
  tcase_add_test(tc, sprintf_test_c4);
  tcase_add_test(tc, sprintf_test_c5);
  tcase_add_test(tc, sprintf_test_c6);
  tcase_add_test(tc, sprintf_test_c7);
  tcase_add_test(tc, sprintf_test_lc1);
  tcase_add_test(tc, sprintf_test_lc2);
  tcase_add_test(tc, sprintf_test_lc3);
  tcase_add_test(tc, sprintf_test_lc4);
  tcase_add_test(tc, sprintf_test_lc5);
  tcase_add_test(tc, sprintf_test_lc6);
  tcase_add_test(tc, sprintf_test_lc7);

  tcase_add_test(tc, sprintf_test_d1);
  tcase_add_test(tc, sprintf_test_d2);
  tcase_add_test(tc, sprintf_test_d3);
  tcase_add_test(tc, sprintf_test_d4);
  tcase_add_test(tc, sprintf_test_d6);
  tcase_add_test(tc, sprintf_test_d7);
  tcase_add_test(tc, sprintf_test_d8);
  tcase_add_test(tc, sprintf_test_d9);
  tcase_add_test(tc, sprintf_test_d10);
  tcase_add_test(tc, sprintf_test_d11);
  tcase_add_test(tc, sprintf_test_d12);
  tcase_add_test(tc, sprintf_test_d13);

  tcase_add_test(tc, sprintf_test_f2);
  tcase_add_test(tc, sprintf_test_f21);
  tcase_add_test(tc, sprintf_test_f22);
  tcase_add_test(tc, sprintf_test_f23);

  tcase_add_test(tc, sprintf_test_f3);

  tcase_add_test(tc, sprintf_test_s1);
  tcase_add_test(tc, sprintf_test_s2);
  tcase_add_test(tc, sprintf_test_s3);
  tcase_add_test(tc, sprintf_test_s4);
  tcase_add_test(tc, sprintf_test_s5);
  tcase_add_test(tc, sprintf_test_s6);
  tcase_add_test(tc, sprintf_test_s7);
  tcase_add_test(tc, sprintf_test_s8);
  tcase_add_test(tc, sprintf_test_ls1);
  tcase_add_test(tc, sprintf_test_ls2);
  tcase_add_test(tc, sprintf_test_ls4);
  tcase_add_test(tc, sprintf_test_ls5);
  tcase_add_test(tc, sprintf_test_ls6);
  tcase_add_test(tc, sprintf_test_ls7);
  tcase_add_test(tc, sprintf_test_ls8);

  tcase_add_test(tc, sprintf_test_u1);
  tcase_add_test(tc, sprintf_test_u2);

  suite_add_tcase(s, tc);

  return s;
}