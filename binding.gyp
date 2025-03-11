{
  "targets": [
    {
      "target_name": "displays",
      "sources": ["linux.cc", "osx.cc", "win.cc", "displays.cc"],
      "include_dirs": [ "<!(node -e \"require('nan')\")" ]
    }
  ],
  "conditions": [
    [ "OS=='mac'",
      {
        "xcode_settings": {
          "GCC_ENABLE_CPP_EXCEPTIONS": "YES",
          'OTHER_CPLUSPLUSFLAGS':[
            "-Wno-c++11-narrowing"
          ]
        },
        "link_settings": {
          "libraries": [
            "-framework",
            "ApplicationServices"
          ]
        }
      }
    ]
  ]
}