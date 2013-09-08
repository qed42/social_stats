<?php

/**
 * @file
 * Returns a content type with number of Twitter tweets of the node.
 * Only available on on node view i.e. with required context node being viewed
 */
$plugin = array(
  'title' => t('Twitter: tweets count'),
  'content_types' => 'twitter',
  'single' => TRUE,
  'category' => array('Social Stats'),
  'edit form' => 'social_stats_twitter_form_edit',
  'render callback' => 'social_stats_twitter_form_render',
  'required context' => array(new ctools_context_required(t('Node'), 'node')),
);

function social_stats_twitter_form_render($subtype, $conf, $args, &$context) {
  $block = new stdClass();
  $tweets_count = db_select('social_stats_twitter', 't')
                  ->fields('t')
                  ->condition('t.nid', $args[0])
                  ->execute()
                  ->fetchObject();
                  dsm($tweets_count);
  if ($tweets_count->tweets == '1') {
    $block->content = $tweets_count->tweets . ' tweet';
  }
  else {
    $block->content = $tweets_count->tweets . ' tweets';
  }  
  return $block;
}

/**
 * Function to render the edit form, if not used doesn't get a form at all.
 */
function social_stats_twitter_form_edit($form, &$form_state) {
  return $form;
}
