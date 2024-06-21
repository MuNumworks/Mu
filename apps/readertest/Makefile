apps += readertest::App
app_headers += apps/readertest/app.h

app_sreadertest_src = $(addprefix apps/readertest/,\
  app.cpp \
  list_book_controller.cpp \
)

apps_src += $(app_sreadertest_src)

app_images += apps/readertest/readertest_icon.png

i18n_files += $(call i18n_without_universal_for,readertest/base)

$(eval $(call depends_on_image,apps/readertest/app.cpp,apps/readertest/readertest_icon.png))