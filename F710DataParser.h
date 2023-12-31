#if !defined(__HIDJOYSTICKRPTPARSER_H__)
#define __HIDJOYSTICKRPTPARSER_H__

#include <usbhid.h>

struct Axis
{
  uint8_t X;
  uint8_t Y;
};

struct GamePadEventData
{
  uint8_t ID;
  Axis AxisL;
  Axis AxisR;
  uint8_t Slider;
  uint8_t Buttons;
};

class JoystickEvents
{
  public:
    virtual void OnGamePadChanged(const GamePadEventData *evt);
};

#define RPT_GAMEPAD_LEN sizeof(GamePadEventData)/sizeof(uint8_t)

class JoystickReportParser : public HIDReportParser
{
  JoystickEvents    *joyEvents;

  uint8_t oldPad[RPT_GAMEPAD_LEN];

  public:
    JoystickReportParser(JoystickEvents *evt);

    virtual void Parse(USBHID *hid, bool is_rpt_id, uint8_t len, uint8_t *buf);
};

#endif // __HIDJOYSTICKRPTPARSER_H__
