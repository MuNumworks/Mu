#include "app.h"
#include "readertest_icon.h"
#include "apps/apps_container.h"
#include "apps/i18n.h"


namespace readertest
{

I18n::Message App::Descriptor::name() 
{
  return I18n::Message::ReadertestApp;
}

I18n::Message App::Descriptor::upperName() 
{
  return I18n::Message::ReadertestAppCapital;
}

const Image * App::Descriptor::icon() 
{
  return ImageStore::ReadertestIcon;
}

App * App::Snapshot::unpack(Container * container) 
{
  return new (container->currentAppBuffer()) App(this);
}

App::Descriptor * App::Snapshot::descriptor()
{
  static Descriptor descriptor;
  return &descriptor;
}

App::App(Snapshot * snapshot) :
  ::App(snapshot, &m_listBookController),
  m_listBookController(nullptr)
{
}

}