<?php

/**
 * Implements hook_views_data
 */
function social_stats_views_views_data() {
  $data = array();

  $data['social_stats_facebook']['table']['group'] = t('Social Stats');

  $data['social_stats_facebook']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );

  $data['social_stats_facebook']['fb_likes'] = array(
    'title' => t('Facebook likes'),
    'help' => t('Number of Facebook likes for this node.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_group_by_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['social_stats_facebook']['fb_shares'] = array(
    'title' => t('Facebook shares'),
    'help' => t('Number of Facebook shares for this node.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['social_stats_facebook']['fb_comments'] = array(
    'title' => t('Facebook comments'),
    'help' => t('Number of Facebook comments on this node.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_group_by_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['social_stats_facebook']['fb_total'] = array(
    'title' => t('Facebook total'),
    'help' => t('Value of (Facebook likes + Facebook shares + Facebook comments).'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_group_by_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['social_stats_twitter']['table']['group'] = t('Social Stats');

  $data['social_stats_twitter']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );

  $data['social_stats_twitter']['tweets'] = array(
    'title' => t('Twitter shares'),
    'help' => t('Value of times this node has been tweeted.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_group_by_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['social_stats_linkedin']['table']['group'] = t('Social Stats');

  $data['social_stats_linkedin']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );

  $data['social_stats_linkedin']['linkedin_shares'] = array(
    'title' => t('LinkedIn shares'),
    'help' => t('Value of times this node has been shared on LinkedIn.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_group_by_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['social_stats_gplus']['table']['group'] = t('Social Stats');

  $data['social_stats_gplus']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );

  $data['social_stats_gplus']['plusone '] = array(
    'title' => t('Google plus shares'),
    'help' => t('Value of times this node has been plus oned on Google Plus.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_group_by_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['social_stats_total']['table']['group'] = t('Social Stats');

  $data['social_stats_total']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );

  $data['social_stats_total']['total_virality'] = array(
    'title' => t('Total social virality'),
    'help' => t('(Facebook total + Twitter Shares + LinkedIn Shares + Google plus shares)'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_group_by_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  return $data;
}
