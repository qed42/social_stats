<?php

/**
 * @file
 * Returns a content type with number of facebook shares of the node.
 * Only available on on node view i.e. with required context node being viewed
 */
$plugin = array(
  'title' => t('Facebook Shares'),
  'content_types' => 'facebook_shares',
  'single' => TRUE,
  'category' => array('Social Stats'),
  'edit form' => 'social_stats_facebook_shares_form_edit',
  'render callback' => 'social_stats_facebook_shares_form_render',
  'required context' => array(new ctools_context_required(t('Node'), 'node')),
);

function social_stats_facebook_shares_form_render($subtype, $conf, $args, &$context) {
  $block = new stdClass();
  $shares_count = db_select('social_stats_facebook', 'fb')
                  ->fields('fb')
                  ->condition('fb.nid', $args[0])
                  ->execute()
                  ->fetchObject();
  if($shares_count->fb_shares == '1') {
    $block->content = $shares_count->fb_shares . ' share';
  }
  else {
    $block->content = $shares_count->fb_shares . ' shares';
  }  
  return $block;
}

function social_stats_facebook_shares_form_edit($form, &$form_state) {
  return $form;
}
