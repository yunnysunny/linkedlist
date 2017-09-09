{
  'targets': [
    {
      # have to specify 'liblib' here since gyp will remove the first one :\
      'target_name': 'native-linked-list',
      'sources': [
        'node/addon.cc',
        'node/NativeLRUList.cc'
      ],
      "include_dirs" : [
        '<!(node -e "require(\'nan\')")',
        'include'
      ]
    }
  ]
}