<?php

/**
 * @file
 * Returns a content type with number of facebook likes on the node.
 * Only available on on node view i.e. with required context node being viewed
 */
$plugin = array(
  'title' => t('Facebook Likes'),
  'content_types' => 'facebook_likes',
  'single' => TRUE,
  'category' => array('Social Stats'),
  'edit form' => 'social_stats_facebook_likes_form_edit',
  'render callback' => 'social_stats_facebook_likes_form_render',
  'required context' => array(new ctools_context_required(t('Node'), 'node')),
);

function social_stats_facebook_likes_form_render($subtype, $conf, $args, &$context) {
  $block = new stdClass();
  $like_count = db_select('social_stats_facebook', 'fb')
                  ->fields('fb')
                  ->condition('fb.nid', $args[0])
                  ->execute()
                  ->fetchObject();
  if($like_count->fb_likes == '1') {
    $block->content = $like_count->fb_likes . ' like';
  }
  else {
    $block->content = $like_count->fb_likes . ' likes';
  }  
  return $block;
}

function social_stats_facebook_likes_form_edit($form, &$form_state) {
  return $form;
}
