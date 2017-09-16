{
  'targets': [
    {
      # have to specify 'liblib' here since gyp will remove the first one :\
      'target_name': 'native-linked-list',
      'sources': [
        'node/addon.cc',
        'node/NodeLRUList.cc'
      ],
      'cflags': ['-fexceptions', '-Wall','-O2'],
      'cflags_cc': ['-fexceptions', '-Wall','-O2'],
      "include_dirs" : [
        '<!(node -e "require(\'nan\')")',
        'include'
      ]
    }
  ]
}